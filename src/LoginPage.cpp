//
// Created by micha on 2021-10-19.
//

#include "LoginPage.h"
#include "Application.h"

LoginPage::LoginPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {

    this->oauth = oauth;
    this->loginButton = new QPushButton("Login with Spotify", this);

    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonY = ((Application::APPLICATION_HEIGHT / 3) * 2) - (buttonHeight / 2);
    int buttonX = (Application::APPLICATION_WIDTH / 2) - (buttonWidth / 2);
    this->loginButton->setGeometry(QRect(QPoint(buttonX, buttonY), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::grant);

    int labelWidth = 190;
    int labelHeight = 70;
    int labelY = (Application::APPLICATION_HEIGHT / 3) - (labelHeight / 2);
    int labelX = (Application::APPLICATION_WIDTH / 2) - (labelWidth / 2);
    this->label = new QLabel("Rhythm", this);
    this->label->setGeometry(QRect(QPoint(labelX, labelY), QSize(labelWidth, labelHeight)));
    this->label->setObjectName("title");
}
