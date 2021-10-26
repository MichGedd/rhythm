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