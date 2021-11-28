
//
// Created by micha on 2021-10-19.
//

#include <HomePage.h>
#include <sstream>
#include <iostream>
#include <Application.h>

using namespace std;

HomePage::HomePage(SpotifyOAuth *oauth, QWidget *parent) : QWidget(parent), oauth(oauth) {
    welcomeString = new QLabel("Home Page", this);
    welcomeString->setObjectName("title");
    welcomeString->setGeometry(QRect(QPoint(50, 100), QSize(Application::APPLICATION_WIDTH, 100)));
}

void HomePage::refreshDisplayName() {
    if(this->oauth->displayName.empty()) {
        std::cout << "Display Name is Empty!" << endl;
        this->oauth->onGetUserInfo();
    }

    string displayName = this->oauth->displayName;

    stringstream ss;
    ss << "Welcome to Rhythm " << displayName << "!";
    string message = ss.str();

    welcomeString->setText(QString::fromStdString(message));
}



