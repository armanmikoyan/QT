#include "friendlist.hpp"

FriendList::FriendList(QWidget *parent)
    : QWidget{parent}
    , mainLayout{new QVBoxLayout{}}
    , mainWidget{new QWidget{this}}
{
    mainWidget->setLayout(mainLayout);
    setFriends();

    mainWidget->setObjectName("mainWidget");
    mainWidget->setStyleSheet("QWidget#mainWidget {border : 5px solid black}");
    mainWidget->setMinimumWidth(300);
    mainWidget->setMinimumHeight(700);
}

void FriendList::setFriends()
{

    QVBoxLayout* friends = new QVBoxLayout{};
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    friends->addWidget(friendFactory());
    mainLayout->addLayout(friends);
}


QWidget* FriendList::friendFactory()
{
    QLabel* username{new QLabel{"Username"}};
    QLabel* logo{new QLabel{"Logo"}};
    QLabel* currentSong{new QLabel{"Current Listening Song"}};

    QHBoxLayout* layout1 = new QHBoxLayout{};
    layout1->addWidget(logo);
    layout1->addWidget(username);

    QVBoxLayout* cardLayout = new QVBoxLayout{};
    cardLayout->addLayout(layout1);
    cardLayout->addWidget(currentSong);

    QWidget* cardWidget = new QWidget;
    cardWidget->setLayout(cardLayout);
    cardWidget->setObjectName("cardWidget");
    cardWidget->setStyleSheet("QWidget#cardWidget {border : 5px solid black;}");

    return cardWidget;

}
