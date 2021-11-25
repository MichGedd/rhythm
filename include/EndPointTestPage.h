//
// Created by krsin on 2021-11-02.
//

#ifndef RHYTHM_ENDPOINTTESTPAGE_H
#define RHYTHM_ENDPOINTTESTPAGE_H

//

#pragma once

#include <QtWidgets>
#include <QMainWindow>
#include <SpotifyOAuth.h>

class EndPointTestPage : public QWidget {
    Q_OBJECT

public:
    EndPointTestPage(SpotifyOAuth *oauth, PlaylistGenerator *playgen, QWidget *parent = nullptr);
private:
    QLabel *label;
    QPushButton *loginButton;
    QPushButton *loginButton1;
    QPushButton *loginButton2;
    SpotifyOAuth *oauth;
    PlaylistGenerator *playgen;


};





#endif //RHYTHM_ENDPOINTTESTPAGE_H
