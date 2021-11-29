#pragma once
#include <QMainWindow>
#include <Application.h>

#define NUM_POINTS 6
QT_BEGIN_NAMESPACE
namespace Ui { class CreatePlaylistPage; }
QT_END_NAMESPACE

class CreatePlaylistPage : public QMainWindow
{
    Q_OBJECT

public:
    CreatePlaylistPage(PlaylistGenerator *playgen, QWidget *parent = nullptr);
    ~CreatePlaylistPage();
    void plot();

private slots:
    void on_pushButton_2_clicked();
    void onPlaylistGenerating();
    void onPlaylistCreated();
    void resetButton();

private:
    PlaylistGenerator *playgen;
    Ui::CreatePlaylistPage *ui;
    QTimer *buttonResetTimer;
};