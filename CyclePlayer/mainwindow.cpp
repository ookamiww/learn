#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    addPlayList();
}

MainWindow::~MainWindow()
{
    delete player;
    delete videoWidget;
    delete list;

}

void MainWindow::init()
{
    player = new QMediaPlayer();
    videoWidget = new QVideoWidget();
    this->setCentralWidget(videoWidget);
    player->setVideoOutput(videoWidget);
    this->showFullScreen();
}

void MainWindow::addPlayList()
{
    QDir dir("/home/ricardo/Videos/test");

    QStringList filters;
    filters << "*.mp4" << "*.avi" << "*.mkv";

    QFileInfoList fileNames = dir.entryInfoList(filters,QDir::Files|QDir::NoSymLinks);

    list = new QMediaPlaylist();
    for (int i = 0; i < fileNames.length(); i++) {
//        qDebug() << fileNames.at(i).absoluteFilePath() << endl;
        list->addMedia(QMediaContent(QUrl::fromLocalFile(fileNames.at(i).absoluteFilePath())));
    }

    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    playVideo();

}

void MainWindow::playVideo()
{
    playerStatus = player->PlayingState;
    player->play();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        exit(0);
}
