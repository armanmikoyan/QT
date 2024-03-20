#include "navbar.hpp"

Navbar::Navbar(QWidget *parent)
    : QWidget{parent}
    , mainLayout{new QVBoxLayout{}}
    , mainWidget{new QWidget{this}}
    , username{new QLabel{"Username"}}
    , logo{new QLabel{"logo"}}
{
    setProfile();
    setCards();

    mainWidget->setLayout(mainLayout);
    mainWidget->setObjectName("mainWidget");
    mainWidget->setStyleSheet("QWidget#mainWidget {border : 5px solid black}");
    mainWidget->setMinimumWidth(300);
    mainWidget->setMinimumHeight(700);
}

void Navbar::setProfile()
{
    QWidget* prifleWidget = new QWidget{};
    QHBoxLayout* profileLayout = new QHBoxLayout{};
    prifleWidget->setLayout(profileLayout);
    profileLayout->addWidget(logo);
    profileLayout->addWidget(username);

    prifleWidget->setObjectName("prifleWidget");
    prifleWidget->setStyleSheet("QWidget#prifleWidget {border : 5px solid black}");
    mainLayout->addWidget(prifleWidget);
}

void Navbar::setCards()
{
    QVBoxLayout* cards = new QVBoxLayout{};
    cards->addWidget(cardFactory());
    cards->addWidget(cardFactory());
    cards->addWidget(cardFactory());
    cards->addWidget(cardFactory());
    cards->addWidget(cardFactory());
    cards->addWidget(cardFactory());

    mainLayout->addLayout(cards);
}


QWidget* Navbar::cardFactory()
{
    QLabel* logo{new QLabel{"Logo"}};
    QLabel* title{new QLabel{"Title"}};
    QLabel* song_count{new QLabel{"44 Songs"}};

    QWidget* cardWidget = new QWidget{};
    cardWidget->setObjectName("cardWidget");
    cardWidget->setStyleSheet("QWidget#cardWidget {border : 5px solid black}");
    QVBoxLayout* infoLayout = new QVBoxLayout{};
    infoLayout->addWidget(title);
    infoLayout->addWidget(song_count);
    QHBoxLayout* card = new QHBoxLayout{};
    card->addWidget(logo);
    card->addLayout(infoLayout);
    cardWidget->setLayout(card);
    cardWidget->setMaximumHeight(70);

    return cardWidget;
}


