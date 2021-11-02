//
// Created by micha on 2021-10-18.
//
#include <SpotifyOAuth.h>
#include <QtGui>
#include <QtNetworkAuth>
#include <iostream>

SpotifyOAuth::SpotifyOAuth(QObject *parent) : QObject(parent) {
    QOAuthHttpServerReplyHandler *replyHandler = new QOAuthHttpServerReplyHandler(1234, this);
    this->oauth2.setReplyHandler(replyHandler);
    this->oauth2.setAuthorizationUrl(QUrl(SpotifyOAuth::AUTHORIZE_URL));
    this->oauth2.setAccessTokenUrl(QUrl(SpotifyOAuth::TOKEN_URL));
    this->oauth2.setScope(SpotifyOAuth::SCOPES);
    this->oauth2.setClientIdentifier(SpotifyOAuth::CLIENT_ID);
    this->oauth2.setClientIdentifierSharedKey(SpotifyOAuth::CLIENT_SECRET);


    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::statusChanged, [=](QAbstractOAuth::Status status) {
        std::cout << "Callback recieved\n";

        if(status == QAbstractOAuth::Status::Granted) {
            std::cout << "Authorize Granted\n";
            // Do something when authenticated
            emit authenticated();
        } else if(status == QAbstractOAuth::Status::NotAuthenticated) {
            std::cout << "Not Authorized\n";
            // Do something when authenticated
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
        std::cout << tempToken.toStdString();
//        std::cout << "Authorize not granted\n";
        // Should probably have some sort of error if we can't authenticate
    });

    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
}

void SpotifyOAuth::grant() {
    this->oauth2.grant();
}

QString SpotifyOAuth::getToken() {
    return this->oauth2.token();
}

//void SpotifyOAuth::onGetUserInfo() {
//    QUrl u ("https://api.spotify.com/v1/me");
//
//    auto reply = oauth2.get(u);
//
//    connect(reply, &QNetworkReply::finished, [=]() {
//        if (reply->error() != QNetworkReply::NoError) {
//            printf("ERROR IN NETWORK CONNECT");
//            return;
//        }
//        const auto data = reply->readAll();
//        const auto document = QJsonDocument::fromJson(data);
//        const auto root = document.object();
//        const auto userName = root.value("id").toString();
//    }
//}

