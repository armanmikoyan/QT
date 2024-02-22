#include "filehandler.hpp"

fileHandler::fileHandler(QString& path, QObject *parent)
    : _file{path}
    , QObject{parent}
{}


int fileHandler::readFile(QVector<int>& _array)
{

    if (_file.open(QIODevice::ReadOnly)) {
        QTextStream input(&_file);
        while (!input.atEnd())
        {
            QString line = input.readLine();
            bool OK = false;
            int num = line.toInt(&OK);
            if (OK)
            {
                _array.push_back(num);
            }
            else
            {
                return -1;
            }
        }
        _file.close();
    }
    else
    {
        qDebug() << "cant open file";
        return -1;
    }
    return 1;
}

int fileHandler::writeToFile(QVector<int>& _array)
{
    if(_file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&_file);
        for (auto num : _array)
        {
            QString line = QString::number(num);
            out << line << "\n";
        }
    }
}
