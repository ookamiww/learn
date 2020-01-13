#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filterFileName();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::filterFileName()
{
    dir = new QDir("/home/ricardo/Videos/Africa no Salaryman");

    //判断文件夹是否存在
    if(!dir->exists())
        return;

    //设置筛选条件
    filters = new QStringList();
    *filters << "*.mp4" << "*.mkv" << "*.avi";

    dir->setFilter(QDir::Files | QDir::NoSymLinks);
    dir->setNameFilters(*filters);

    QStringList *fileNames = new QStringList();
    *fileNames = dir->entryList();

    for (int i = 0; i < fileNames->length(); i++) {

        qDebug() << fileNames->at(i) << endl;

    }

}
