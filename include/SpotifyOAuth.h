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

//ALGORITHM TEAM: will need a function that gets "duration_ms" from a song given the track id

//TYPE: GET
//NAME: getMultipleTracksFeatures(String id)
//LINK: https://api.spotify.com/v1/tracks
//PURPOSE: Get the audio features of multiple tracks
//HEADERS: "Authorization:  " "Content-type: application/json"

//ALGORITHM TEAM: does not need (yet, although it would likly be needed for editing current playlists that the user has)

//TYPE: GET
//NAME: getTrackAnalysis(String id)
//LINK: https://api.spotify.com/v1/tracks/{id}
//PURPOSE: Get a detailed analysis on a specific track
//HEADERS: "Authorization:  " "Content-type: application/json"

//ALGORITHM TEAM: does not need (yet, although it would likly be needed for editing current playlists that the user has)

//TYPE: GET
//NAME: getRecommendation(String seed_artists, String seed_genres, String seed_tracks, int limit)
//LINK: https://api.spotify.com/v1/recommendations
//PURPOSE: Will return a list of recommended songs by the features given.  artists, genres, tracks are given above but there are more options
//HEADERS: "Authorization:  " "Content-type: application/json"

//ALGORITHM TEAM: will need a function that takes the seed artists, genres, tracks, and limit along with a vector of target names and target values. Returns an array of song IDs or some other way to identify the songs
//We can make sure the target names match how they are documented in the API so for example the dancibility variable will be named "target_danceability". 
//Also, as of now all target values are heald as floats as that is what the majority of the ones in the API are. Some casting may be required to properly make the call to the API

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

//-----------ADDED BY ALGORITHM TEAM---------------- 
//TYPE: POST
//NAME: createPlaylist(String playlistName)
//LINK: https://api.spotify.com/v1/users/{user_id}/playlists
//PURPOSE: Create a new playlist so songs can be added to it
//HEADERS: "Authorization:  " "Content-type: application/json"

//TYPE: GET
//NAME: getUsersTopItems()
//LINK: https://api.spotify.com/v1/me/top/{type}
//PURPOSE: get information about the user's preferences for choosing seed artists, generes, and tracks
//HEADERS: "Authorization:  " "Content-type: application/json"

//this one may not be required but we need a way to get a seed generes and seed artists from a track, don't know if
//this is already possible or if there is an easier way to do this
//can't find a way to get the genere of a track so maybe we just limit our application to a large set of generes??? or REQUIRE user pick the genere(s)
//TYPE: GET
//NAME: getArtist(String id)
//LINK: https://api.spotify.com/v1/tracks/{id}
//PURPOSE: get information about a track and extract the artist name
//HEADERS: "Authorization:  " "Content-type: application/json"



