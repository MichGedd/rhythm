//
// Created by micha on 2021-10-19.
//

#include "LoginPage.h"

LoginPage::LoginPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {
    this->oauth = oauth;
    this->loginButton = new QPushButton("Login", this);
    this->loginButton->setGeometry(QRect(QPoint(295, 324), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::grant);
}
