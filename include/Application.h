//
// Created by micha on 2021-10-19.
//

#pragma once

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>


class Application : public QObject {
    Q_OBJECT

public:
    Application(QObject *parent = nullptr);


private slots:
    void loginToMainPage();

private:
    QWidget *window;
    QStackedWidget *stackedWidget;
    QVBoxLayout *layout;
};
