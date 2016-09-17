#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "openbrmanager.h"
#include "imageloader.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectBR(OpenBRManager *obr);
    void connectImageLoader(ImageLoader *imgLoader);

private:
    Ui::MainWindow *ui;

public slots:
    void showImage(QImage *img, QString str);
};

#endif // MAINWINDOW_H
