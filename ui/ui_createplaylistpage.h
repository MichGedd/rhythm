/********************************************************************************
** Form generated from reading UI file 'createplaylistpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPLAYLISTPAGE_H
#define UI_CREATEPLAYLISTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_CreatePlaylistPage
{
public:
    QWidget *centralwidget;
    QCustomPlot *plot;
    QSlider *slider;
    QComboBox *comboBox;
    QLineEdit *timeInput;
    QPushButton *setTimeButton;
    QRadioButton *radioButton;
    QPushButton *pushButton_2;
    QLabel *timeNote;
    QLineEdit *playlistName;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreatePlaylistPage)
    {
        if (CreatePlaylistPage->objectName().isEmpty())
            CreatePlaylistPage->setObjectName(QString::fromUtf8("CreatePlaylistPage"));
        CreatePlaylistPage->resize(848, 480);
        centralwidget = new QWidget(CreatePlaylistPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(280, 100, 350, 230));
        slider = new QSlider(centralwidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(725, 100, 50, 230));
        slider->setOrientation(Qt::Vertical);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(330, 390, 270, 20));
        timeInput = new QLineEdit(centralwidget);
        timeInput->setObjectName(QString::fromUtf8("timeInput"));
        timeInput->setGeometry(QRect(20, 110, 113, 22));
        setTimeButton = new QPushButton(centralwidget);
        setTimeButton->setObjectName(QString::fromUtf8("setTimeButton"));
        setTimeButton->setGeometry(QRect(160, 110, 93, 28));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(230, 390, 95, 20));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(670, 380, 160, 40));
        timeNote = new QLabel(centralwidget);
        timeNote->setObjectName(QString::fromUtf8("timeNote"));
        timeNote->setGeometry(QRect(20, 150, 241, 20));
        playlistName = new QLineEdit(centralwidget);
        playlistName->setObjectName(QString::fromUtf8("playlistName"));
        playlistName->setGeometry(QRect(20, 190, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(174, 190, 81, 16));
        CreatePlaylistPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreatePlaylistPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 848, 25));
        CreatePlaylistPage->setMenuBar(menubar);
        statusbar = new QStatusBar(CreatePlaylistPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreatePlaylistPage->setStatusBar(statusbar);

        retranslateUi(CreatePlaylistPage);

        QMetaObject::connectSlotsByName(CreatePlaylistPage);
    } // setupUi

    void retranslateUi(QMainWindow *CreatePlaylistPage)
    {
        CreatePlaylistPage->setWindowTitle(QCoreApplication::translate("CreatePlaylistPage", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("CreatePlaylistPage", "Energy", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("CreatePlaylistPage", "Acousticness", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("CreatePlaylistPage", "Liveness", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("CreatePlaylistPage", "Speechiness", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("CreatePlaylistPage", "Valence", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("CreatePlaylistPage", "Danceability", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("CreatePlaylistPage", "Instrumentalness", nullptr));

        timeInput->setText(QCoreApplication::translate("CreatePlaylistPage", "20", nullptr));
        setTimeButton->setText(QCoreApplication::translate("CreatePlaylistPage", "Set Time", nullptr));
        radioButton->setText(QCoreApplication::translate("CreatePlaylistPage", "Add Graph", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreatePlaylistPage", "Create Playlist", nullptr));
        timeNote->setText(QCoreApplication::translate("CreatePlaylistPage", "Note: Changing time will reset all graphs", nullptr));
        playlistName->setText(QCoreApplication::translate("CreatePlaylistPage", "Rhythm Playlist", nullptr));
        label->setText(QCoreApplication::translate("CreatePlaylistPage", "Playlist Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePlaylistPage: public Ui_CreatePlaylistPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPLAYLISTPAGE_H
