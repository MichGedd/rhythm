//
// Created by micha on 2021-10-19.
//

#include <Application.h>
#include <LoginPage.h>
#include <HomePage.h>
#include <CreatePlaylistPage.h>

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
    LoginPage *loginPage = new LoginPage(&oauth);
    connect(&(this->oauth), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

    HomePage *homePage = new HomePage;

    CreatePlaylistPage *createPlaylistPage = new CreatePlaylistPage;

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);
    this->stackedWidget->addWidget(createPlaylistPage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);
    this->layout->setContentsMargins(0, 0, 0, 0);

    /**
     * IMPORTANT - THIS IS JUST TO BYPASS THE LOGIN PAGE AND IMMEDIATELY GET TO THE CREATE PLAYLIST PAGE
     * DELETE THIS LINE ONCE YOU NEED SPOTIFY API ACCESS OR DELETE IT BEFORE MERGING TO MASTER
     */
    this->stackedWidget->setCurrentIndex(2);

    window->show();
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(1);
}


