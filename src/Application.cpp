//
// Created by micha on 2021-10-19.
//

#include <Application.h>
#include <LoginPage.h>
#include <HomePage.h>

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
    this->navBar = new NavBar(window);
    this->navBar->raise();
    connect(this->navBar, &NavBar::logout, this, &Application::logout);

    // Initialize pages
    LoginPage *loginPage = new LoginPage(&oauth);
    connect(&(this->oauth), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

    HomePage *homePage = new HomePage;

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);
    this->layout->setContentsMargins(0, 0, 0, 0);

    this->navBar->raise();  // Raise the navbar to the top of the screen
    window->show();
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(1);
    this->navBar->show();
}

void Application::logout() {
    this->stackedWidget->setCurrentIndex(0);
    this->navBar->hide();
}



