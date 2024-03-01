#include "navbar.hpp"

Navbar::Navbar(QWidget *parent)
    : QWidget{parent}
    , layout{new QVBoxLayout{}}
{
    setNavbar();
}


Navbar::~Navbar()
{
    delete layout;
}

void Navbar::setNavbar()
{
    QPushButton* homeBtn = new QPushButton("Home", this);
    QPushButton* playlistsBtn = new QPushButton("Playlists", this);
    QPushButton* settingsBtn = new QPushButton("Settings", this);


    for (auto btn : {homeBtn, playlistsBtn, settingsBtn})
    {
        btn->setMinimumWidth(100);
        layout->addWidget(btn);
    }
    layout->setAlignment(Qt::AlignTop);

    connect(homeBtn, &QPushButton::clicked, this, &Navbar::onClick);
    connect(playlistsBtn, &QPushButton::clicked, this, &Navbar::onClick);
    connect(settingsBtn, &QPushButton::clicked, this, &Navbar::onClick);
}

QVBoxLayout* Navbar::getLayout() const
{
    return layout;
}

void Navbar::onClick()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    enum singalNums
    {
        Home,
        Playlists,
        Settings
    };

    const QString& whichButtonClicked = clickedButton->text();
    int signal{};

    if (whichButtonClicked == "Home")
    {
        signal = singalNums::Home;
    }
    else if(whichButtonClicked == "Playlists")
    {
        signal = singalNums::Playlists;
    }
    else if (whichButtonClicked == "Settings")
    {
        signal = Settings;
    }

    emit pageSwapSignal(signal);
}
