#ifndef OPENBRMANAGER_H
#define OPENBRMANAGER_H

#include <QObject>
#include <QSharedPointer>

class OpenBRManager : public QObject
{
    Q_OBJECT

public:
    OpenBRManager();
    ~OpenBRManager();

private:
    QString actualImagePath;

signals:
    void imageProcessed();

public slots:
    void saveImagePath(QString str);
    void processImage();

};

#endif // OPENBRMANAGER_H
