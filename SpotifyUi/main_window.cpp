#include "main_window.hpp"
#include "ui_main_window.h"

#include "components/musicPlayer/musicplayer.hpp"
#include "components/navbar/navbar.hpp"
#include "components/friends/friendlist.hpp"
#include "components/body/body.hpp"
#include "components/search/searchbar.hpp"

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_window)
    , mainLayout{new QGridLayout{}}
    , mainWidget{new QWidget}
{
    Navbar* navbar = new Navbar{};
    MusicPlayer* player = new MusicPlayer{};
    FriendList* friends = new FriendList{};
    Body* body = new Body{};
    SearchBar* searchBar = new SearchBar{};


    mainLayout->addWidget(player, 7, 0, 1, 9);

    mainLayout->addWidget(navbar, 0, 0, 5, 2);
    mainLayout->addWidget(friends, 0, 7,5, 2);

    mainLayout->addWidget(body, 1, 2, 4, 7);
    mainLayout->addWidget(searchBar, 0, 2, 1, 7);











    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
}

main_window::~main_window()
{
    delete ui;
}
