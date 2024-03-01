#include "playlistpage.hpp"

PlaylistPage::PlaylistPage(QWidget *parent)
    : QWidget{parent}
    , widget{new QWidget{this}}
    , layout{new QVBoxLayout{widget}}
    , pageName{new QLabel{"Playlists Page", this}}

    ,   music1{new QLabel{"Music 1" }}
    ,   music2{new QLabel{"Music 2"}}
    ,   music3{new QLabel{"Music 3"}}
    ,   music4{new QLabel{"Music 4"}}
    ,   music5{new QLabel{"Music 5"}}
{
    setPlaylist();
}


PlaylistPage::~PlaylistPage()
{
    delete layout;
}


QVBoxLayout* PlaylistPage::getLayout() const
{
    return layout;
}

QWidget* PlaylistPage::getWidget() const
{
    return widget;
}


void PlaylistPage::setPlaylist()
{
    layout->addWidget(pageName);


    layout->addWidget(music1);
    layout->addWidget(music2);
    layout->addWidget(music3);
    layout->addWidget(music4);
    layout->addWidget(music5);

    // set another widgets for ui ...
}
