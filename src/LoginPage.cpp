//
// Created by micha on 2021-10-19.
//

#include "LoginPage.h"

LoginPage::LoginPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {
    this->oauth = oauth;
    this->loginButton = new QPushButton("Login with Spotify", this);
    this->loginButton->setGeometry(QRect(QPoint(295, 324), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::grant);

    this->label = new QLabel("Rhythm", this);
    this->label->setGeometry(QRect(QPoint(295, 124), QSize(200, 50)));
    this->label->setObjectName("title");
}
