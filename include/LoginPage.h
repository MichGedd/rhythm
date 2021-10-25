//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QMainWindow>

#include "SpotifyOAuth.h"

class LoginPage : public QWidget {
    Q_OBJECT

public:
    LoginPage(SpotifyOAuth *oauth, QWidget *parent = nullptr);

private:
    QLabel *label;
    QPushButton *loginButton;
    SpotifyOAuth *oauth;

};
