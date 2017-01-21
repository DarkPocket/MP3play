#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    player=new QMediaPlayer(this);
    //创建播放列表，并在列表里添加两首歌曲
    mediaList=new QMediaPlaylist;

    mediaList->addMedia(QUrl::fromLocalFile("F:/MI3/computer/mp3/common/潮鳴り-电影原声.mp3"));
    mediaList->setCurrentIndex(1);
    player->setPlaylist(mediaList);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_But_play_clicked()
{
    if (ui->But_play->text()=="播放")
    {
        player->play();

          QString title = player->metaData("Title").toString();
        ui->  lab_mediaName->setText(title);
        //lab_mediaName
        ui->But_play->setText(tr("暂停"));
    }
    else
    {
        player->pause();
        ui->But_play->setText(tr("播放"));
    }
}

//FileInfoList
void MainWindow:: test( )
{
    QString path="F:/MI3/computer/mp3/test";


    QFileInfoList file;

    file= GetFileList(path);
    for(int i = 0; i != file.size(); i++)
    {
        QString Filename = file.at(i).absoluteFilePath();
        qDebug()<< Filename<<"";

         mediaList->addMedia(QUrl::fromLocalFile(Filename));

    }
    qDebug()<< mediaList->mediaCount()<<" 歌曲数目 \n";

}

QFileInfoList MainWindow:: GetFileList(QString path)
{
    QDir dir(path);
    QStringList filters;

    filters << "*.mp3";
    filters << "*.wma";
 //   filters << "*.flac";
//    filters << "*.wma";


    //  filters<<QString("*.jpeg")<<QString("*.jpg")<<QString("*.png")<<QString("*.tiff")<<QString("*.gif")<<QString("*.bmp");
    dir.setNameFilters(filters); //这个就是设置过滤的文件名使用通配符

    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i = 0; i != folder_list.size(); i++)
    {
        QString name = folder_list.at(i).absoluteFilePath();
        QFileInfoList child_file_list = GetFileList(name);
        file_list.append(child_file_list);
    }

    return file_list;
}


void MainWindow::on_pushButton_clicked()
{
    test( );
}

void MainWindow::on_but_MediaPre_clicked()
{
    mediaList->previous();
    player->play();

}

void MainWindow::on_but_MediaNext_clicked()
{
    int currentIndex=mediaList->currentIndex();
    if(++currentIndex==mediaList->mediaCount())
        currentIndex=0;
    mediaList->setCurrentIndex(currentIndex);

}
