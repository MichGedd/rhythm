//
// Created by micha on 2021-10-19.
//

#include "Application.h"
#include "LoginPage.h"
#include "HomePage.h"

#include <iostream>

Application::Application(QObject *parent) : QObject(parent), oauth() {

    // Initialize pages
    LoginPage *loginPage = new LoginPage(&oauth);
    connect(&(this->oauth), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

    HomePage *homePage = new HomePage;

    this->window = new QWidget;
    this->window->resize(848, 480);

    this->window->setStyleSheet("QObject {\n"
                                "    background-color: rgb(56, 53, 53);\n"
                                "}\n"
                                "\n"
                                "QPushButton {\n"
                                "    background-color: rgb(41, 85, 239);\n"
                                "    color: white;\n"
                                "    \n"
                                "}");

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);
    this->layout->setContentsMargins(0, 0, 0, 0);

    window->show();
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(1);
}


