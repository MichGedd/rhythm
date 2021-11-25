
//
// Created by micha on 2021-10-19.
//

#include <HomePage.h>
#include <QLabel>

HomePage::HomePage(QWidget *parent) : QWidget(parent) {
    QLabel *label = new QLabel("Home Page", this);
    label->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
}
