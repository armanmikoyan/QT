#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , navbar{new Navbar{this}}
    , playlistPage{new PlaylistPage{this}}
    , homePage{new HomePage{this}}
    , settingsPage{new SettingsPage{this}}
    , player{new Player{this}}
    , pageStack{new QStackedLayout{}}

{
    ui->setupUi(this);
    mainLayout = new QGridLayout{ui->centralwidget};

    setStack();
    setMainLayout();

    connect(navbar, &Navbar::pageSwapSignal, this, &MainWindow::changePage);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pageStack;
}


void MainWindow::setStack()
{
    pageStack->addWidget(homePage->getWidget());
    pageStack->addWidget(playlistPage->getWidget());
    pageStack->addWidget(settingsPage->getWidget());
}


void MainWindow::setMainLayout()
{

    mainLayout->addLayout(navbar->getLayout(), 0, 0, 0, 0, Qt::AlignTop | Qt::AlignLeft);
    mainLayout->addLayout(pageStack, 0, 1, 0, 1, Qt::AlignTop | Qt::AlignLeft);
    mainLayout->addLayout(player->getLayout(),  3, 0,  2, 1, Qt::AlignBottom | Qt::AlignRight);
}

void MainWindow::changePage(int i)
{
    pageStack->setCurrentIndex(i);
}

