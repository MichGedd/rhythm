//
// Created by micha on 2021-10-26.
//

#pragma once
#include <QtWidgets>

class NavBar : public QFrame {
    Q_OBJECT

public:
    NavBar(QWidget *parent = nullptr);

signals:
    void logout();
    void goToCreatePlaylist();
    void goToSavedPlaylist();

private slots:
    void logoutButtonPressed();
    void createPlaylistButtonPressed();
    void savedPlaylistButtonPressed();
    
private:
    QPushButton *createPlaylist;
    QPushButton *savedPlaylists;
    QPushButton *logoutButton;

};
