#include "player.hpp"

Player::Player(QWidget *parent)
    : QWidget{parent}
    , vlayout{new QVBoxLayout{}}
    , hlayout{new QHBoxLayout{}}
    , slider{new QSlider{Qt::Horizontal}}
    , next{new QPushButton{"Next", this}}
    , prev{new QPushButton{"Prev", this}}
{
    setPlayer();
}

Player::~Player()
{
    delete vlayout;
}


void Player::setPlayer()
{
    hlayout->addWidget(prev);
    hlayout->addWidget(next);

    vlayout->addLayout(hlayout);
    vlayout->addWidget(slider);
}

QVBoxLayout* Player::getLayout() const
{
    return vlayout;
}
