#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>

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

signals:
    void brClear();

public slots:
    void showImage(QString str);
    void showResults(Age::Range range, Gender::Type gender);

private slots:
    void reset();
    void clear();
};

#endif // MAINWINDOW_H
