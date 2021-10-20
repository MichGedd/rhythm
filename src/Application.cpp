//
// Created by micha on 2021-10-19.
//

#include "Application.h"
#include "LoginPage.h"
#include "HomePage.h"

Application::Application(QObject *parent) : QObject(parent) {
    // Initialize pages
    LoginPage *loginPage = new LoginPage;
    connect(loginPage->getSpotifyOAuth(), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

    HomePage *homePage = new HomePage;

    this->window = new QWidget;
    window->resize(400, 400);

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);

    window->show();
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(1);
}
