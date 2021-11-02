//
// Created by micha on 2021-10-18.
//

#pragma once

#include <QtCore>
#include <QtNetwork>
#include <QOAuth2AuthorizationCodeFlow>

class SpotifyOAuth : public QObject {
    Q_OBJECT
public:
    SpotifyOAuth(QObject *parent = nullptr);

    QString getToken();

//    GET function to get all of the users information
    void onGetUserInfo();

public slots:
    void grant();

signals:
    void authenticated();


private:
    const QString AUTHORIZE_URL = "https://accounts.spotify.com/authorize";
    const QString TOKEN_URL = "https://accounts.spotify.com/api/token";
    const QString SCOPES = "user-library-modify user-top-read";

    // TODO: Find a better way to store secrets.
    const QString CLIENT_ID = "***REMOVED***";
    const QString CLIENT_SECRET = "***REMOVED***";

    QOAuth2AuthorizationCodeFlow oauth2;
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
//NAME: getRecommendation(String seed_artists, String see_genres, String seed_tracks, int limit)
//LINK: https://api.spotify.com/v1/recommendations
//PURPOSE: Will return a list of recommended songs by the features given.  artists, genres, tracks are given above but there are more options
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