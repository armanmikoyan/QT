#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "person.hpp"
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void write_to_file();
    void render_ui();

private:
    Ui::MainWindow    *ui;
    Person* last_person{};

};
#endif // MAINWINDOW_HPP
