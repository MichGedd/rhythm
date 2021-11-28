//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QWidget>
#include <SpotifyOAuth.h>
#include <QLabel>

class HomePage : public QWidget {
    Q_OBJECT

public:
    HomePage(SpotifyOAuth *oauth, QWidget *parent = nullptr);

public slots:
    void refreshDisplayName();

private:
    SpotifyOAuth *oauth;
    QLabel *welcomeString;
};
