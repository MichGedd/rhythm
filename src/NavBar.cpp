//
// Created by micha on 2021-10-26.
//

#include <NavBar.h>
#include <Application.h>

NavBar::NavBar(QWidget *parent) : QFrame(parent) {
    this->setGeometry(0, 0, Application::APPLICATION_WIDTH, 75);
    this->setObjectName("navBar");

    int logoutButtonWidth = 100;
    int logoutButtonHeight = 50;
    int logoutButtonX = Application::APPLICATION_WIDTH - logoutButtonWidth - 10;  // The 10px is a padding
    int logoutButtonY = 10;
    this->logoutButton = new QPushButton("Logout", this);
    this->logoutButton->setGeometry(logoutButtonX, logoutButtonY, logoutButtonWidth, logoutButtonHeight);

    connect(this->logoutButton, &QPushButton::released, this, &NavBar::logoutButtonPressed);
}

void NavBar::logoutButtonPressed() {
    emit logout();
}

