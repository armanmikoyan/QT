#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QObject>
#include "filehandler.hpp"
#include <chrono>
#include "sorter.hpp"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QVector>


class application : public QObject
{
    Q_OBJECT

    enum class _strategy
    {
        none,
        bubble,
        selection,
        insertion
    };

public:
    explicit application(Ui::MainWindow*, QObject *parent = nullptr);

public:
    void connections();

public slots:
    void onFileSelectorClicked();
    void onStrategyClicked();
    void onSortClicked();

private:
    Ui::MainWindow *ui{};
    enum _strategy strategy{};
    QString file{};
    QVector<int> array;
    Sorter* algo{};
};

#endif // APPLICATION_HPP
