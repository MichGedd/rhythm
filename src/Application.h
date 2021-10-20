//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>


class Application  {
public:
    Application();

private:
    QWidget *window;
    QStackedWidget *stackedWidget;
    QVBoxLayout *layout;
};
