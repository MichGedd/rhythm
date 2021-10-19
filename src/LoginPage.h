//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QMainWindow>

#include "SpotifyOAuth.h"

class LoginPage : public QMainWindow {
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);

private:
    QPushButton *loginButton;
    SpotifyOAuth oauth;

};
