//
// Created by micha on 2021-10-18.
//
#include <SpotifyOAuth.h>
#include <QtGui>
#include <QtNetworkAuth>
#include <iostream>
#include <string>

using namespace std;


SpotifyOAuth::SpotifyOAuth(QObject *parent) : QObject(parent) {
    QOAuthHttpServerReplyHandler *replyHandler = new QOAuthHttpServerReplyHandler(1234, this);
    this->oauth2.setReplyHandler(replyHandler);
    this->oauth2.setAuthorizationUrl(QUrl(SpotifyOAuth::AUTHORIZE_URL));
    this->oauth2.setAccessTokenUrl(QUrl(SpotifyOAuth::TOKEN_URL));
    this->oauth2.setScope(SpotifyOAuth::SCOPES);
    this->oauth2.setClientIdentifier(SpotifyOAuth::CLIENT_ID);
    this->oauth2.setClientIdentifierSharedKey(SpotifyOAuth::CLIENT_SECRET);
    this->songToBeAdded = "";
    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::statusChanged, [=](QAbstractOAuth::Status status) {
        std::cout << "Callback recieved\n";

        if(status == QAbstractOAuth::Status::Granted) {
            std::cout << "Authorize Granted\n";
            this->onGetTopArtist();
            this->onGetTopTrack();
            this->runGetRecommendations();

            // Do somethin--g when authenticated
            emit authenticated();
        } else if(status == QAbstractOAuth::Status::NotAuthenticated) {
            std::cout << "Not Authorized\n";
            emit authenticated();
        } else if(status == QAbstractOAuth::Status::TemporaryCredentialsReceived) {
            std::cout << "Temporarily Authorized\n";
            // Do something when authenticated

            emit authenticated();

        } else if(status == QAbstractOAuth::Status::RefreshingToken) {
            std::cout << "Refreshing Token\n";
            // Do something when authenticated
            emit authenticated();
        }
        QString tempToken = getToken();
        std::cout << tempToken.toStdString() << std::endl;
//        std::cout << "Authorize not granted\n";
        // Should probably have some sort of error if we can't authenticate
    });

    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
}

void SpotifyOAuth::grant() {

    this->oauth2.grant();
//    this->onGetTopTrack();
//    this->onGetTopArtist();
}

QString SpotifyOAuth::getToken() {
    return this->oauth2.token();
}

void SpotifyOAuth::onGetUserInfo() {
    QUrl u ("https://api.spotify.com/v1/me");

    auto reply = oauth2.get(u);
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            std::cout << reply->errorString().toStdString() << std::endl;
            printf("ERROR IN NETWORK CONNECT");
            return;
        }
        const auto data = reply->readAll();
        const auto document = QJsonDocument::fromJson(data);
        const auto root = document.object();
        const auto userName = root.value("id").toString().toStdString();
        std::cout << userName << std::endl;
    });
}

void SpotifyOAuth::onGetRecommendations(vector<string> *songURL, vector<string> seed_emotions,vector<float> seed_values,  QString seedGenre, QString seedArtists, QString seedTracks){


    QUrl u ("https://api.spotify.com/v1/recommendations");
    QVariantMap parameters;

    QString input;

    for(int i = 0; i < seed_emotions.size(); i++){
        input = QString::fromStdString("target_" + seed_emotions[i]);
        parameters.insert(input, seed_values[i]);
    }

    int limit = 1;
    QString genres = seedGenre; //"classical,country";
    QString artists = seedArtists;//"4NHQUGzhtTLFvgF5SZesLK";
    QString tracks = seedTracks; //"0c6xIDDpzE81m2q797ordA";


//HOW TO PASS PARAMETERS
    parameters.insert("seed_genres",genres);
    parameters.insert("seed_artists",artists);
    parameters.insert("seed_tracks",tracks);
    parameters.insert("limit",limit);
    string response;


    //auto reply = oauth2.get(u, parameters);
    QNetworkReply *reply;
    reply = oauth2.get(u, parameters);

    connect(reply, &QNetworkReply::finished, [=]() {

        if (reply->error() != QNetworkReply::NoError) {
            std::cout << reply->errorString().toStdString() << std::endl;
            printf("ERROR IN NETWORK CONNECT");
            return;
        }
        const auto data = reply->readAll();
        const auto document = QJsonDocument::fromJson(data);
        const auto root = document.object();
        const QString trackNames = root.value("tracks").toArray()[0].toObject().value("uri").toString();
        cout << trackNames.toStdString() << endl;
        songURL->push_back(trackNames.toStdString());
        emit recommendationSignal();
    });

//    std::cout << reply << std::endl;

};


void SpotifyOAuth::onGetTopTrack() {
    QUrl u ("https://api.spotify.com/v1/me/top/tracks");
    auto reply = oauth2.get(u);
    QString Tracks;
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() != QNetworkReply::NoError) {
            std::cout << reply->error() << std::endl;
            std::cout << reply->errorString().toStdString() << std::endl;
            printf("ERROR IN NETWORK CONNECT");
            return;
        }
        const auto data = reply->readAll();
        const auto document = QJsonDocument::fromJson(data);
        const auto root = document.object();
        const int totalNum = root.value("total").toInt();
        if (totalNum <= 0 ) {
            std::cout << "You don't have any top songs or artists to based recommendation off of." << endl;
            return;
        }
        //Return track URI
        QString trackNames = root.value("items").toArray()[0].toObject().value("uri").toString();

     std::cout << trackNames.toStdString() << std::endl;
    });

}

void SpotifyOAuth::onGetTopArtist() {

    QUrl v ("https://api.spotify.com/v1/me/top/artists");
    auto replyartists = oauth2.get(v);
    std::string response;
    connect(replyartists, &QNetworkReply::finished, [=]() {
    if (replyartists->error() != QNetworkReply::NoError) {
    printf("ERROR IN NETWORK CONNECT");
    return;
    }

    const auto data = replyartists->readAll();
    const auto document = QJsonDocument::fromJson(data);
    const auto root = document.object();
    const int totalNum = root.value("total").toInt();
    if (totalNum <= 0 ) {
    std::cout << "You don't have any top songs or artists to based recommendation off of." << endl;
//    *artist = 'Error';
    return;
    }
    //Return artist URI
    const auto trackNames = root.value("items").toArray()[0].toObject().value("uri").toString();

    std::cout << trackNames.toStdString() << endl;
//    *artist = trackNames;
    return;
    });
}

void SpotifyOAuth::createPlaylist() {
    QUrl v ("https://api.spotify.com/v1/users/gmx8drhtdos7sem71t32xt5ad/playlists");
    QJsonObject parameters;
    parameters["name"] = "NewPLaylistTitle";
    parameters["description"] = "New playlist description";
    parameters["public"] = 1;
    QJsonDocument doc(parameters);
    QByteArray data = doc.toJson();

    auto replyartists = oauth2.post(v, data);
    connect(replyartists, &QNetworkReply::finished, [=]() {
        if (replyartists->error() != QNetworkReply::NoError) {
            std::cout << replyartists->error() << std::endl;
            std::cout << replyartists->errorString().toStdString() << std::endl;
            printf("ERROR IN NETWORK CONNECT");
            return;
        }
        const auto data = replyartists->readAll();
        const auto document = QJsonDocument::fromJson(data);
        const auto root = document.object();
        const auto totalNum = root.value("name").toString();
        std::cout << totalNum.toStdString() << std::endl;
    });

}

void SpotifyOAuth::addToPlaylist(std::string playlistID, std::string trackURI) {
    std::string url = "https://api.spotify.com/v1/playlists/";
    url = url + playlistID + "/tracks?uris=" + trackURI;
    QUrl v (QString::fromStdString(url));

    QJsonObject parameters;
    parameters["name"] = "NewPLaylistTitle";
    parameters["description"] = "New playlist description";
    parameters["public"] = 1;
    QJsonDocument doc(parameters);
    QByteArray data = doc.toJson();

    auto replyartists = oauth2.post(v, data);
    connect(replyartists, &QNetworkReply::finished, [=]() {
        if (replyartists->error() != QNetworkReply::NoError) {
            std::cout << replyartists->error() << std::endl;
            std::cout << replyartists->errorString().toStdString() << std::endl;
            printf("ERROR IN NETWORK CONNECT");
            return;
        }

        const auto data = replyartists->readAll();
        const auto document = QJsonDocument::fromJson(data);

        std::cout << "Added item to playlist" << std::endl;
    });

}

void SpotifyOAuth::runGetRecommendations() {
    QString genres = "classical,country";
    QString tracks = "4NHQUGzhtTLFvgF5SZesLK";
    QString artists = "4NHQUGzhtTLFvgF5SZesLK";

    //need to add this so it will run

    vector<string> variableNames;
    variableNames.push_back("energy");
    vector<float> values;
    values.push_back(0.6);
    vector<string> songURL;

//    this->onGetRecommendations(&songURL, variableNames, values, genres, artists, tracks);
    std::cout << "RECOMMENDATION" << std::endl;

    if(songURL.empty()){
        cout << "no recommendation received\n";
    }
}

void SpotifyOAuth::runAddtoPlaylist() {
    QString response;
    std::string tracks = "spotify:track:1Gcg62WCWynIyjilpHFYTJ";
    std::string playlist = "1tFohRckqPRqBrgRfzaVn0";
    this->addToPlaylist( playlist, tracks);
    std::cout << "ADDED" << std::endl;
    }

string SpotifyOAuth::getSongToBeAdded() {
    return songToBeAdded;
}