#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>
#include <QFileInfo>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *list;
    QMediaPlayer::State playerStatus;

    void init();
    void addPlayList();
    void playVideo();

private slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
