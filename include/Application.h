//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>

#include "SpotifyOAuth.h"


class Application : public QObject {
    Q_OBJECT

public:
    Application(QObject *parent = nullptr);


private slots:
    void loginToMainPage();

private:
    const static int APPLICATION_WIDTH = 848;
    const static int APPLICATION_HEIGHT = 480;

    QWidget *window;
    QStackedWidget *stackedWidget;
    QVBoxLayout *layout;
    SpotifyOAuth oauth;
};
