#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QGridLayout>
#include <QStackedLayout>

#include "navbar.hpp"
#include "playlistpage.hpp"
#include "homePage.hpp"
#include "settingspage.hpp"

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

    void setMainLayout();
    void setStack();
    void changePage(int);

private:
    Ui::MainWindow *ui;

    Navbar* navbar;
    PlaylistPage* playlistPage;
    HomePage* homePage;
    SettingsPage* settingsPage;

    QGridLayout* mainLayout;
    QStackedLayout* pageStack;

};
#endif // MAINWINDOW_HPP
