//
// Created by micha on 2021-10-18.
//

#pragma once

#include <QtCore>
#include <QtNetwork>
#include <QOAuth2AuthorizationCodeFlow>
#include <string>
using namespace std;

class SpotifyOAuth : public QObject {
    Q_OBJECT


public slots:
    void grant();

signals:
    void authenticated();


private:
    const QString AUTHORIZE_URL = "https://accounts.spotify.com/authorize";
    const QString TOKEN_URL = "https://accounts.spotify.com/api/token";
    const QString SCOPES = "user-library-modify user-top-read playlist-modify-public playlist-modify-private user-read-private user-read-email";

    // TODO: Find a better way to store secrets.
    const QString CLIENT_ID = "***REMOVED***";
    const QString CLIENT_SECRET = "***REMOVED***";

    QOAuth2AuthorizationCodeFlow oauth2;

public:
    string songToBeAdded;
//    string playlistID;
//    string topTrack;
//    string topArtist;


    SpotifyOAuth(QObject *parent = nullptr);

    QString getToken();

//TYPE: GET
//NAME: onGetUserInfo(String id)
//LINK: https://api.spotify.com/v1/audio-features/{id}
//PURPOSE: function to get all of the users information. Needed right after login to get the user ID and can pull all other info from there
//HEADERS: "Authorization:  " "Content-type: application/json"
    //    GET function to get all of the users information
    void onGetUserInfo();

//TYPE: GET
//NAME: onGetRecommendations(String seed_artists, String see_genres, String seed_tracks, int limit)
//LINK: https://api.spotify.com/v1/recommendations
//PURPOSE: Will return a list of recommended songs by the features given.  artists, genres, tracks are given above but there are more options
//HEADERS: "Authorization:  " "Content-type: application/json"
    void onGetRecommendations(vector<string> seed_emotions,vector<float> seed_values, QString seedGenre, QString seedArtists, QString seedTracks);

    void runGetRecommendations();


//TYPE: GET
//NAME: onGetTopItem(int type)
//LINK: https://api.spotify.com/v1/me/top/{type}
//PURPOSE: Get the top track or atrist from user
//HEADERS: "Authorization:  " "Content-type: application/json"
    string getSongToBeAdded();
    void onGetTopTrack();
    void onGetTopArtist();
    void createPlaylist();
    void addToPlaylist(std::string playlistID, std::string trackURI);
    void runAddtoPlaylist();

    string onGetRecommendations(vector<string> songURL, vector<string> seed_emotions, vector<float> seed_values,
                                QString seedGenre, QString seedArtists, QString seedTracks);
};



//TYPE: GET
//NAME: getTrackFeatures(String id)
//LINK: https://api.spotify.com/v1/audio-features/{id}
//PURPOSE: Get the audio features of a track
//HEADERS: "Authorization:  " "Content-type: application/json"


//TYPE: GET
//NAME: getMultipleTracksFeatures(String id)
//LINK: https://api.spotify.com/v1/tracks
//PURPOSE: Get the audio features of multiple tracks
//HEADERS: "Authorization:  " "Content-type: application/json"

//TYPE: GET
//NAME: getTrackAnalysis(String id)
//LINK: https://api.spotify.com/v1/tracks/{id}
//PURPOSE: Get a detailed analysis on a specific track
//HEADERS: "Authorization:  " "Content-type: application/json"


//TYPE: GET
//NAME: getPlaylist(String id)
//LINK: https://api.spotify.com/v1/playlists/{id}
//PURPOSE: Get all information and details on playlist specified
//HEADERS: "Authorization:  " "Content-type: application/json"

//TYPE: GET
//NAME: getPlaylistItems(String id)
//LINK: https://api.spotify.com/v1/playlists/{id}/tracks
//PURPOSE: Get all tracks information from platlist
//HEADERS: "Authorization:  " "Content-type: application/json"

//TYPE: POST
//NAME: addItemstoPlaylist(String playlist_id, String uris[], int position )
//LINK: https://api.spotify.com/v1/playlists/{playlist_id}/tracks
//PURPOSE: Add multiple or a singular track to a playlist at a specified position
//HEADERS: "Authorization:  " "Content-type: application/json"

//TYPE: DELETE
//NAME: deletePlaylist(String id)
//LINK: https://api.spotify.com/v1/playlists/{id}/tracks
//PURPOSE: Get a detailed analysis on a specific track
//HEADERS: "Authorization:  " "Content-type: application/json"