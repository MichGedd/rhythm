//
// Created by micha on 2021-10-19.
//

#include <Application.h>
#include <LoginPage.h>
#include <HomePage.h>
#include <CreatePlaylistPage.h>
#include <SavedPlaylistPage.h>
#include <mainwindow.h>

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
    connect(this->navBar, &NavBar::goToCreatePlaylist, this, &Application::switchToCreatePlaylist);
    connect(this->navBar, &NavBar::goToSavedPlaylist, this, &Application::switchToSavedPlaylists);
    connect(this->navBar, &NavBar::goToHomePage, this, &Application::switchToHomePage);

    // Initialize pages
    LoginPage *loginPage = new LoginPage(&oauth);
    connect(&(this->oauth), &SpotifyOAuth::authenticated, this, &Application::loginToMainPage);

    HomePage *homePage = new HomePage;

    CreatePlaylistPage *createPlaylistPage = new CreatePlaylistPage;

    MainWindow *mainWindow = new MainWindow;
    mainWindow->resize(200, 200);

    SavedPlaylistPage *savedPlaylistPage = new SavedPlaylistPage;

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);
    this->stackedWidget->addWidget(homePage);
    //this->stackedWidget->addWidget(createPlaylistPage);
    this->stackedWidget->addWidget(mainWindow);
    this->stackedWidget->addWidget(savedPlaylistPage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);
    this->layout->setContentsMargins(0, 0, 0, 0);

    this->navBar->raise();  // Raise the navbar to the top of the screen
    this->navBar->hide();  // Dont show the navbar on login screen
    window->show();

    this->stackedWidget->setCurrentIndex(2);
}

void Application::loginToMainPage() {
    this->stackedWidget->setCurrentIndex(1);
    this->navBar->show();
}

void Application::logout() {
    this->stackedWidget->setCurrentIndex(0);
    this->navBar->hide();
}

void Application::switchToCreatePlaylist() {
    this->stackedWidget->setCurrentIndex(2);
}

void Application::switchToSavedPlaylists() {
    this->stackedWidget->setCurrentIndex(3);
}

void Application::switchToHomePage() {
    this->stackedWidget->setCurrentIndex(1);
}





