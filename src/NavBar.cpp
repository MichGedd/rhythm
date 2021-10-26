//
// Created by micha on 2021-10-26.
//

#include <NavBar.h>
#include <Application.h>

NavBar::NavBar(QWidget *parent) : QFrame(parent) {
    this->setGeometry(0, 0, Application::APPLICATION_WIDTH, 50);
    this->setObjectName("navBar");

    this->logoutButton = new QPushButton("Logout", this);
    this->logoutButton->setGeometry(0, 0, 100, 50);
}

