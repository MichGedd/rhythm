//
// Created by micha on 2021-10-19.
//

#include "LoginPage.h"

LoginPage::LoginPage(QWidget *parent) : QWidget(parent), oauth() {
    // TODO Delete
}

LoginPage::LoginPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {
    this->oauth = oauth;
    this->loginButton = new QPushButton("Login", this);
    this->loginButton->setGeometry(QRect(QPoint(295, 324), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::grant);

    /*QPalette backgroundColor = QPalette();
    backgroundColor.setColor(QPalette::Background, QColor::fromRgb(56, 53, 53));
    this->setAutoFillBackground(true);
    this->setPalette(backgroundColor);

    this->loginButton->setStyleSheet("background-color: rgb(41, 85, 239); color: white;");*/
}
