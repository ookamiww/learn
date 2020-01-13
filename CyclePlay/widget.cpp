#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    init();
    addPlayList();

}

Widget::~Widget()
{

}

/**
 * 初始化窗口
 * @brief Widget::init
 */
void Widget::init()
{
    player = new QMediaPlayer();
    videoWidget = new QVideoWidget();
    player->setVideoOutput(videoWidget);
    QLayout *layout = new QVBoxLayout(this);
    layout->addWidget(videoWidget);
    videoWidget->setFullScreen(true);

}

/**
 * 添加视频文件夹,检测文件夹中的视频并加入播放列表
 * @brief Widget::addPlayList
 */
void Widget::addPlayList()
{
    dir = new QDir("/home/ricardo/Videos/");

    QStringList filters;
    filters << "*.mp4" << "*.avi" << "*.mkv";

    QFileInfoList fileNames = dir->entryInfoList(filters,QDir::Files|QDir::NoSymLinks);

    list = new QMediaPlaylist();
    for (int i = 0; i < fileNames.length(); i++) {
//        qDebug() << fileNames.at(i).absoluteFilePath() << endl;
        list->addMedia(QMediaContent(QUrl::fromLocalFile(fileNames.at(i).absoluteFilePath())));
    }

    list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setPlaylist(list);
    playVideo();

}

/**
 * 播放视频
 * @brief Widget::playVideo
 */
void Widget::playVideo()
{
    playerStatus = player->PlayingState;
    player->play();
}

/**
 * Esc键退出程序
 * @brief Widget::keyPressEvent
 * @param event
 */
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
        exit(0);
}
