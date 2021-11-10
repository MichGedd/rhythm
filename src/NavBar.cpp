//
// Created by micha on 2021-10-26.
//

#include <NavBar.h>
#include <Application.h>

NavBar::NavBar(QWidget *parent) : QFrame(parent) {
    this->setGeometry(0, 0, Application::APPLICATION_WIDTH, 75);
    this->setObjectName("navBar");

    int buttonWidth = 100;
    int buttonHeight = 50;
    int buttonY = 10;
    int logoutButtonX = Application::APPLICATION_WIDTH - buttonWidth - 10;  // The 10px is a padding
    this->logoutButton = new QPushButton("Logout", this);
    this->logoutButton->setGeometry(logoutButtonX, buttonY, buttonWidth, buttonHeight);
    connect(this->logoutButton, &QPushButton::released, this, &NavBar::logoutButtonPressed);

    int createPlaylistButtonX = (Application::APPLICATION_WIDTH / 3) - (buttonWidth / 2);
    this->createPlaylist = new QPushButton("Create Playlist", this);
    this->createPlaylist->setGeometry(createPlaylistButtonX, buttonY, buttonWidth, buttonHeight);
    connect(this->createPlaylist, &QPushButton::released, this, &NavBar::createPlaylistButtonPressed);


    int savedPlaylistButtonX = ((Application::APPLICATION_WIDTH / 3) * 2) - (buttonWidth / 2);
    this->savedPlaylists = new QPushButton("Saved Playlists", this);
    this->savedPlaylists->setGeometry(savedPlaylistButtonX, buttonY, buttonWidth, buttonHeight);
    connect(this->savedPlaylists, &QPushButton::released, this, &NavBar::savedPlaylistButtonPressed);



}

void NavBar::logoutButtonPressed() {
    emit logout();
}

void NavBar::createPlaylistButtonPressed() {
    emit goToCreatePlaylist();
}

void NavBar::savedPlaylistButtonPressed() {
    emit goToSavedPlaylist();
}

