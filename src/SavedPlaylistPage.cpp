//
// Created by micha on 2021-11-12.
//

#include <SavedPlaylistPage.h>
#include <QLabel>

SavedPlaylistPage::SavedPlaylistPage(QWidget *parent) : QWidget(parent) {
    QLabel *label = new QLabel("Saved Playlist Page", this);
    label->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
}
