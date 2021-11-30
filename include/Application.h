//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>
#include <SpotifyOAuth.h>
#include <NavBar.h>
#include <PlaylistAlgorithm.h>

class Application : public QObject {
    Q_OBJECT

public:
    Application(QObject *parent = nullptr);
    const static int APPLICATION_WIDTH = 848;
    const static int APPLICATION_HEIGHT = 480;


private slots:
    void loginToMainPage();
    void logout();
    void switchToCreatePlaylist();
    void switchToHomePage();


private:
    QWidget *window;
    QStackedWidget *stackedWidget;
    QVBoxLayout *layout;
    SpotifyOAuth oauth;
    PlaylistGenerator playGen;
    NavBar *navBar;

};
