#include "playlistAlgorithm.h"

using namespace std;

//implementation of constructor method
PlaylistGenerator::PlaylistGenerator(SpotifyOAuth *oauth, QObject *parent) : QObject(parent) {
    this->oauth = oauth;
    //convert playlistLength to ms from minutes
    playlistDuration_ms = 0;
    currentDuration_ms = 0;
}
PlaylistGenerator::PlaylistGenerator(QObject *parent) : QObject(parent) {
    oauth = nullptr;
    //convert playlistLength to ms from minutes
    playlistDuration_ms = 0;
    currentDuration_ms = 0;
}



void PlaylistGenerator::getGraphs(vector<graph> inputGraphs, int playlistLength){
    graphs = inputGraphs;
    //convert playlistLength to ms from minutes
    playlistDuration_ms = playlistLength * MS_IN_MINUTE;
    currentDuration_ms = 0;
}

void PlaylistGenerator::generatePlaylists() {
    int i;
    float slope;
    while (currentDuration_ms < playlistDuration_ms) {
        variableNames.clear();
        values.clear();
        for (graph g: graphs) {
            i = 1;
            //move through graph until the current duration is just past point 'i'
            while ((g.points[i].time_minutes * MS_IN_MINUTE) < currentDuration_ms) i++;
            //get slope of line between point i and i-1
            slope = (float) (g.points[i].value - g.points[i - 1].value) /
                    (float) (g.points[i].time_minutes - g.points[i - 1].time_minutes);
            //target name is same as name on graph
            variableNames.push_back(g.variableName);
            //calculate target value as y = mx + b
            //convert currentDuration into minutes for calculation
            values.push_back(
                    slope * (currentDuration_ms / MS_IN_MINUTE - g.points[i - 1].time_minutes) + g.points[i - 1].value);
        }
        //use target values structure to search for a song through Spotify API with all the requirements
        //cout << "\nTime = " << currentDuration_ms/MS_IN_MINUTE << " minutes -> Search for:\n";

        //API code goes here

        QString genres = "classical,country";
        QString tracks = "4NHQUGzhtTLFvgF5SZesLK";
        QString artists = "4NHQUGzhtTLFvgF5SZesLK";

        this->oauth->onGetRecommendations(&songURIs, variableNames, values, genres, artists, tracks);
        cout << "SONG URL: " << songURIs[0];

        /*
        top track
        top artists

        currentDuration_ms += onGetTrackDuration();

        targetSongs.clear();

        //------------------now generate the playlist-------------------
        //create new playlist
        onCreatePlaylist(); //add playlist name, description, public: false
        //add list of tracks to playlist
        //maximum of 100 in 1 request

        //NEED THE SPOTIFY URIS TO ADD THE SONG TO THE PLAYLIST

        onAddItemsToPlaylist(songIDs);
        */



        //add the songID of the recommended song onto the list of songIDs
        //replace '5' with correct ID for the song
//        songURIs.push_back("abc123");
//
//        //add the song duration to the current playlist duration
//        //hard coded value of 180 000 ms = 3 minutes
//        currentDuration_ms += 3 * MS_IN_MINUTE;
//
//        //clear target values for next set on inputs from graph
//        targetSongs.clear();
    }
    //cout << "Generated playlist duration: " << currentDuration_ms/MS_IN_MINUTE << '\n';
}

void PlaylistGenerator::addPlaylistToAccount(){
    //search through list of songURIs
    //onCreatePlaylist();
    //max of 100 at a time!

    if(songURIs.size() > 100){
        vector<string>::const_iterator first;
        vector<string>::const_iterator last;
        for(int i = 0; i < songURIs.size(); i += 100) {
            first = songURIs.begin() + i;
            if(i + 99< songURIs.size()) {
                last = songURIs.begin() + i + 99;
            }
            else{
                last = songURIs.end();
            }
            vector<string> subset(first, last);
            //onAddToPlaylist(playlistID, subset);
        }
    }
    else{
        //onAddTrackToPlaylist(playlistID, songURIs);
    }

}

void PlaylistGenerator::clamp(float min, float max, float &number) {
    if(number > max){
        number = max;
        return;
    }
    if(number < min){
        number = min;
    }
}