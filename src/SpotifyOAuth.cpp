//
// Created by micha on 2021-10-18.
//
#include <QtGui>
#include <QtNetworkAuth>

#include "SpotifyOAuth.h"

SpotifyOAuth::SpotifyOAuth(QObject *parent) : QObject(parent) {
    QOAuthHttpServerReplyHandler *replyHandler = new QOAuthHttpServerReplyHandler(1234, this);
    this->oauth2.setReplyHandler(replyHandler);
    this->oauth2.setAuthorizationUrl(QUrl("https://accounts.spotify.com/authorize")); // Probably should make this const
    this->oauth2.setAccessTokenUrl(QUrl("https://accounts.spotify.com/api/token"));  // Probably should make this const
    this->oauth2.setScope("user-library-modify user-top-read");  // Make these const
    this->oauth2.setClientIdentifier("***REMOVED***");  // What to do with secrets?
    this->oauth2.setClientIdentifierSharedKey("***REMOVED***");


    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::statusChanged, [=](QAbstractOAuth::Status status) {
        if(status == QAbstractOAuth::Status::Granted) {
            // Do something when authenticated
            emit authenticated();
        }
        // Should probably have some sort of error if we can't authenticate
    });

    connect(&(this->oauth2), &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, &QDesktopServices::openUrl);
}

SpotifyOAuth::SpotifyOAuth(const QString &clientIdentifier, QObject *parent) : SpotifyOAuth(parent) {
    this->oauth2.setClientIdentifier(clientIdentifier);
}

void SpotifyOAuth::grant() {
    this->oauth2.grant();
}
