#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileInfoList>
#include <QMediaPlaylist>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QFileInfoList GetFileList(QString path);

    void test();
private slots:
    void on_But_play_clicked();

    void on_pushButton_clicked();

    void on_but_MediaPre_clicked();

    void on_but_MediaNext_clicked();

private:
    Ui::MainWindow *ui;


    QMediaPlayer  *player;
    QMediaPlaylist  *mediaList;

    QFileInfoList *FileInfoList;

};

#endif // MAINWINDOW_H
