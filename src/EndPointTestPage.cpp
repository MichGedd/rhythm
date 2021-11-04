//
// Created by krsin on 2021-11-02.
//
#include <Application.h>
#include "EndPointTestPage.h"

EndPointTestPage::EndPointTestPage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent) {

    this->oauth = oauth;
    this->loginButton = new QPushButton("NEW PAGE", this);

    int buttonWidth = 200;
    int buttonHeight = 50;
    int buttonY = ((Application::APPLICATION_HEIGHT / 3) * 2) - (buttonHeight / 2);
    int buttonX = (Application::APPLICATION_WIDTH / 2) - (buttonWidth / 2);
    this->loginButton->setGeometry(QRect(QPoint(buttonX, buttonY), QSize(200, 50)));
    connect(this->loginButton, &QPushButton::released, this->oauth, &SpotifyOAuth::onGetRecommendations);

    int labelWidth = 190;
    int labelHeight = 70;
    int labelY = (Application::APPLICATION_HEIGHT / 3) - (labelHeight / 2);
    int labelX = (Application::APPLICATION_WIDTH / 2) - (labelWidth / 2);
    this->label = new QLabel("TEST PAGE", this);
    this->label->setGeometry(QRect(QPoint(labelX, labelY), QSize(labelWidth, labelHeight)));
    this->label->setObjectName("title");

}