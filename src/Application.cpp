//
// Created by micha on 2021-10-19.
//

#include "Application.h"
#include "LoginPage.h"

Application::Application() {

    // Initialize pages
    LoginPage *loginPage = new LoginPage;

    this->window = new QWidget;
    window->resize(400, 400);

    // Add pages to stacked widget
    this->stackedWidget = new QStackedWidget;
    this->stackedWidget->addWidget(loginPage);

    this->layout = new QVBoxLayout(window);
    this->layout->addWidget(this->stackedWidget);

    window->show();
}
