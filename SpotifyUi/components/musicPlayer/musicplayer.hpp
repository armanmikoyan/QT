#ifndef MUSICPLAYER_HPP
#define MUSICPLAYER_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QComboBox>

class MusicPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit MusicPlayer(QWidget *parent = nullptr);

private:
    void setLeftSide();
    void setMidSide();
    void setRightSide();

private:
    QLabel* music_name;
    QLabel* artist_name;
    QLabel* logo;

    QProgressBar* progressBar;
    QPushButton* next;
    QPushButton* prev;
    QPushButton* playStop;

    QComboBox* friendList;
    QLabel* nextSong;
    QHBoxLayout* mainLayout;
    QWidget* wrapperWidget;
};

#endif // MUSICPLAYER_HPP
