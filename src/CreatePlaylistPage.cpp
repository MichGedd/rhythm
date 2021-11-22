//
// Created by micha on 2021-11-10.
//

#include <CreatePlaylistPage.h>
#include <QLabel>

CreatePlaylistPage::CreatePlaylistPage(QWidget *parent) : QWidget(parent) {
    QLabel *label = new QLabel("Create Playlist Page", this);
    label->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
}