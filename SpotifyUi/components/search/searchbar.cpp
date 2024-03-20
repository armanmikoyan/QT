#include "searchbar.hpp"

SearchBar::SearchBar(QWidget *parent)
    : QWidget{parent}
    , searchBar{new QLineEdit}
    , mainLayout{new QVBoxLayout{}}
    , mainWidget{new QWidget{this}}
{
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(searchBar);

    searchBar->setObjectName("searchBar");
    searchBar->setMinimumWidth(750);
    searchBar->setText("Search...");
    searchBar->setStyleSheet("QWidget#searchBar {border : 5px solid black; font-size: 25px; border-radius: 15px}");
}
