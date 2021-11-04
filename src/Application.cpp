//
// Created by micha on 2021-10-19.
//

#include <Application.h>
#include <LoginPage.h>
#include <EndPointTestPage.h>

#include <HomePage.h>

#include <iostream>

Application::Application(QObject *parent) : QObject(parent), oauth() {

    // Initialize container
    this->window = new QWidget;
    this->window->resize(Application::APPLICATION_WIDTH, Application::APPLICATION_HEIGHT);
    QFile file("resources/main.css");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    this->window->setStyleSheet(in.readAll());

    // Initialize pages
    EndPointTestPage *endPointTestPage = new EndPointTestPage(&oauth);
    LoginPage *loginPage = new LoginPage(&oauth);
    connect(&(this->oauth), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

//    // Initialize pages
//    connect(&(this->oauth), &SpotifyOAuth::onGetUserInfo, this, &Application::moveToTestPage);

    HomePage *homePage = new HomePage;

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);
    this->stackedWidget->addWidget(endPointTestPage);


    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);
    this->layout->setContentsMargins(0, 0, 0, 0);

    window->show();
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(2);
}
void Application::moveToTestPage() {
    this->stackedWidget->setCurrentIndex(1);
}


