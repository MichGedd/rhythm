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

public slots:
    void grant();

signals:
    void authenticated();

private:
    QOAuth2AuthorizationCodeFlow oauth2;
};