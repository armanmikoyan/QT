#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <QObject>
#include <QFile>
#include <QVector>
#include <qDebug>
#include <QTextStream>

class fileHandler : public QObject
{
    Q_OBJECT
public:
    explicit fileHandler(QString&, QObject *parent = nullptr);
public:
    int readFile(QVector<int>&);
    int writeToFile(QVector<int>&);

private:

    QFile _file;
};

#endif // FILEHANDLER_HPP
