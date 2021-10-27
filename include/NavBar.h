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

private slots:
    void logoutButtonPressed();
    
private:
    QPushButton *createPlaylist;
    QPushButton *savedPlaylists;
    QPushButton *logoutButton;

};
