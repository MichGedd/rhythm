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
    SpotifyOAuth(const QString &clientIdentifier, QObject *parent = nullptr);

    QString getToken();

public slots:
    void grant();

signals:
    void authenticated();

private:
    QOAuth2AuthorizationCodeFlow oauth2;

    const QString authorizeUrl = "https://accounts.spotify.com/authorize";
    const QString tokenUrl = "https://accounts.spotify.com/api/token";
    const QString scopes = "user-library-modify user-top-read";

    // TODO: Find a better way to store secrets.
    const QString clientID = "***REMOVED***";
    const QString clientSecret = "***REMOVED***";
};