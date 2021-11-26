#include "playlistAlgorithm.h"

using namespace std;

//implementation of constructor method
PlaylistGenerator::PlaylistGenerator(SpotifyOAuth *oauth, QObject *parent) : QObject(parent) {
    this->oauth = oauth;
    //convert playlistLength to ms from minutes
    playlistDuration_ms = 10;
    currentDuration_ms = 0;
    currSong = "";
    connect(oauth, &SpotifyOAuth::recommendationSignal, this, &PlaylistGenerator::recommendationCallback);
    connect(this, &PlaylistGenerator::calculateSignal, this, &PlaylistGenerator::calculate);

}
PlaylistGenerator::PlaylistGenerator(QObject *parent) : QObject(parent) {
    oauth = nullptr;
    //convert playlistLength to ms from minutes
    playlistDuration_ms = 10;
    currentDuration_ms = 0;
    currSong = "";

}



void PlaylistGenerator::getGraphs(vector<graph> inputGraphs, int playlistLength){
    graphs = inputGraphs;

    if(graphs.empty()){
        cout << "no graphs received";
    }

    //convert playlistLength to ms from minutes
    playlistDuration_ms = playlistLength * MS_IN_MINUTE;
    currentDuration_ms = 0;
    currSong = "";
}

void PlaylistGenerator::calculate() {
    QString genres = "classical,country";
    QString tracks = "4NHQUGzhtTLFvgF5SZesLK";
    QString artists = "4NHQUGzhtTLFvgF5SZesLK";
    this->oauth->onGetRecommendations(&songURIs, variableNames, values, genres, artists, tracks);

}

void PlaylistGenerator::generatePlaylists(){
    int i;
    float slope;
        for(int j = 0; j< 2; j++) {
            //while(currentDuration_ms < playlistDuration_ms)
            values.clear();
            variableNames.clear();
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
                float value =
                        slope * (currentDuration_ms / MS_IN_MINUTE - g.points[i - 1].time_minutes) + g.points[i - 1].value;
                values.push_back(value);

                //add the target to the list of targets to use for recommendations

            }
            //use target values structure to search for a song through Spotify API with all the requirements
            cout << "\nTime = " << currentDuration_ms / MS_IN_MINUTE << " minutes -> Search for:\n";
            //API code goes here
//            calculate(variablename, variablevalue);

            //ensure that the target.value is within the limits for the specific variable!!!!!

//        cout << "Reach here" << endl;
            emit calculate();
        }
    }


void PlaylistGenerator::addPlaylistToAccount() {
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

void PlaylistGenerator::recommendationCallback(){
    if (songURIs.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << "SONGURI: " << songURIs[0] << endl;
        //UPDATE THE TIME

        currentDuration_ms += 3 * MS_IN_MINUTE;
    }
}