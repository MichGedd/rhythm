#pragma once
#include <QMainWindow>

#define NUM_POINTS 6
QT_BEGIN_NAMESPACE
namespace Ui { class CreatePlaylistPage; }
QT_END_NAMESPACE

class CreatePlaylistPage : public QMainWindow
{
    Q_OBJECT

public:
    CreatePlaylistPage(QWidget *parent = nullptr);
    ~CreatePlaylistPage();
    void plot();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::CreatePlaylistPage *ui;
};