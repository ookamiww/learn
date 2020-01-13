#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>
#include <QFileInfo>
#include <QKeyEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QMediaPlaylist *list;
    QMediaPlayer::State playerStatus;
    QDir *dir;

    void init();
    void addPlayList();
    void playVideo();

private slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // WIDGET_H
