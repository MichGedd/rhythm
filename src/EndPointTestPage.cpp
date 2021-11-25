//
// Created by krsin on 2021-11-02.
//
#include <Application.h>
#include <iostream>
#include "EndPointTestPage.h"




EndPointTestPage::EndPointTestPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {

    this->oauth = oauth;


    this->loginButton = new QPushButton("create", this);
    this->loginButton1 = new QPushButton("recommend", this);
    this->loginButton2 = new QPushButton("Add", this);

    int buttonWidth = 100;
    int buttonHeight = 50;
    int buttonY = ((Application::APPLICATION_HEIGHT / 3) * 2) - (buttonHeight / 2);
    int buttonX = (Application::APPLICATION_WIDTH / 4);
    QString response;

    this->loginButton->setGeometry(QRect(QPoint(buttonX - (buttonWidth / 2), buttonY), QSize(200, 50)));
    this->loginButton1->setGeometry(QRect(QPoint(buttonX*2 - (buttonWidth / 2), buttonY), QSize(200, 50)));
    this->loginButton2->setGeometry(QRect(QPoint(buttonX*3 - (buttonWidth / 2), buttonY), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::createPlaylist);
    connect(this->loginButton1, &QPushButton::released, this->oauth, &SpotifyOAuth::runGetRecommendations);
    connect(this->loginButton2, &QPushButton::released, this->oauth, &SpotifyOAuth::runAddtoPlaylist);

    int labelWidth = 190;
    int labelHeight = 70;
    int labelY = (Application::APPLICATION_HEIGHT / 3) - (labelHeight / 2);
    int labelX = (Application::APPLICATION_WIDTH / 2) - (labelWidth / 2);
    this->label = new QLabel("TEST PAGE", this);
    this->label->setGeometry(QRect(QPoint(labelX, labelY), QSize(labelWidth, labelHeight)));
    this->label->setObjectName("title");

}

