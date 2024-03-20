#include "musicplayer.hpp"

MusicPlayer::MusicPlayer(QWidget *parent)
    : QWidget{parent}
    , music_name{new QLabel{"Music Name"}}
    , artist_name{new QLabel{"Artist Name"}}
    , logo{new QLabel{"Logo"}}
    , progressBar{new QProgressBar{}}
    , next{new QPushButton{">"}}
    , prev{new QPushButton{"<"}}
    , playStop{new QPushButton{"||"}}
    , friendList{new QComboBox{}}
    , nextSong{new QLabel{"Next song name"}}
    , mainLayout{new QHBoxLayout{this}}
    , wrapperWidget{new QWidget(this)}
{
    wrapperWidget->setLayout(mainLayout);
    setLeftSide();
    setMidSide();
    setRightSide();
    wrapperWidget->setMinimumHeight(100);
    wrapperWidget->setMinimumWidth(1415);
    wrapperWidget->setObjectName("wrapperObject");
    wrapperWidget->setStyleSheet("QWidget#wrapperObject {border : 5px solid black;}");
}


void MusicPlayer::setMidSide()
{
    QHBoxLayout* layout1 = new QHBoxLayout{};
    layout1->addWidget(prev);
    layout1->addWidget(playStop);
    layout1->addWidget(next);


    QVBoxLayout* wrap = new QVBoxLayout{};
    wrap->addLayout(layout1);
    wrap->addWidget(progressBar);

    mainLayout->addLayout(wrap);
}


void MusicPlayer::setLeftSide()
{
    QVBoxLayout* layout1 = new QVBoxLayout{};
    layout1->addWidget(music_name);
    layout1->addWidget(artist_name);

    QVBoxLayout* layout2 = new QVBoxLayout{};
    layout2->addWidget(logo);

    QHBoxLayout* wrap = new QHBoxLayout{};
    wrap->addLayout(layout2);
    wrap->addLayout(layout1);

    mainLayout->addLayout(wrap);
}

void MusicPlayer::setRightSide()
{
    QVBoxLayout* wrap = new QVBoxLayout{};
    wrap->addWidget(friendList);
    wrap->addWidget(nextSong);
    mainLayout->addLayout(wrap);
}

