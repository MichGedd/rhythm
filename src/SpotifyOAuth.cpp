//
// Created by micha on 2021-10-18.
//
#include <QtGui>
#include <QtNetworkAuth>

#include "SpotifyOAuth.h"

SpotifyOAuth::SpotifyOAuth(QObject *parent) : QObject(parent) {
    QOAuthHttpServerReplyHandler *replyHandler = new QOAuthHttpServerReplyHandler(1234, this);
    this->oauth2.setReplyHandler(replyHandler);
    this->oauth2.setAuthorizationUrl(QUrl(SpotifyOAuth::AUTHORIZE_URL));
    this->oauth2.setAccessTokenUrl(QUrl(SpotifyOAuth::TOKEN_URL));
    this->oauth2.setScope(SpotifyOAuth::SCOPES);
    this->oauth2.setClientIdentifier(SpotifyOAuth::CLIENT_ID);
    this->oauth2.setClientIdentifierSharedKey(SpotifyOAuth::CLIENT_SECRET);


    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::statusChanged, [=](QAbstractOAuth::Status status) {
        if(status == QAbstractOAuth::Status::Granted) {
            // Do something when authenticated
            emit authenticated();
        }
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
