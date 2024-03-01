#include "settingspage.hpp"

SettingsPage::SettingsPage(QWidget *parent)
    : QWidget{parent}
    , widget{new QWidget{this}}
    , layout{new QVBoxLayout{widget}}
    , pageName{new QLabel{"Settings Page", this}}
{
    setSettings();
}

SettingsPage::~SettingsPage()
{
    delete layout;
}


QVBoxLayout* SettingsPage::getLayout() const
{
    return layout;
}

QWidget* SettingsPage::getWidget() const
{
    return widget;
}

void SettingsPage::setSettings()
{
    layout->addWidget(pageName);

    // set another widgets for ui ...
}
