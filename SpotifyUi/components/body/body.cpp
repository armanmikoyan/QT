#include "body.hpp"

Body::Body(QWidget *parent)
    : QWidget{parent}
    , mainLayout{new QVBoxLayout{}}
    , mainWidget{new QWidget{this}}
{
    mainWidget->setLayout(mainLayout);

    mainLayout->addWidget(layerFactory());
    mainLayout->addWidget(layerFactory());
    mainLayout->addWidget(layerFactory());

    mainWidget->setObjectName("mainWidget");
    mainWidget->setStyleSheet("QWidget#mainWidget {border : 5px solid black;}");
}

QWidget* Body::layerFactory()
{
    QWidget* layer = new QWidget{};
    QHBoxLayout* layout = new QHBoxLayout{};
    layout->addWidget(cardFactory());
    layout->addWidget(cardFactory());
    layout->addWidget(cardFactory());
    layout->addWidget(cardFactory());
    layout->addWidget(cardFactory());
    layer->setLayout(layout);
    return layer;
}

QWidget* Body::cardFactory()
{
    QLabel* title{new QLabel{"title"}};
    QLabel* logo{new QLabel{"Logo"}};

    QVBoxLayout* layout1 = new QVBoxLayout{};
    layout1->addWidget(logo);
    layout1->addWidget(title);


    QWidget* cardWidget = new QWidget;
    cardWidget->setLayout(layout1);
    cardWidget->setObjectName("cardWidget");
    cardWidget->setStyleSheet("QWidget#cardWidget {border : 5px solid black;}");
    cardWidget->setMinimumHeight(135);
    cardWidget->setMinimumWidth(135);
    return cardWidget;
}
