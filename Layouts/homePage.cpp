#include "homePage.hpp"

HomePage::HomePage(QWidget *parent)
    : QWidget{parent}
    , widget{new QWidget{this}}
    , layout{new QVBoxLayout{widget}}
    , pageName{new QLabel{"Home", this}}
{
    setHome();
}


HomePage::~HomePage()
{
    delete layout;
}

QVBoxLayout* HomePage::getLayout() const
{
    return layout;
}

QWidget* HomePage::getWidget() const
{
    return widget;
}

void HomePage::setHome()
{
    layout->addWidget(pageName);

    // set another widgets for ui ...
}
