#ifndef PLAYLISTPAGE_HPP
#define PLAYLISTPAGE_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class PlaylistPage : public QWidget
{
    Q_OBJECT
public:
    explicit PlaylistPage(QWidget *parent = nullptr);
    ~PlaylistPage();

public:
    QVBoxLayout* getLayout() const;
    QWidget* getWidget() const;

private:
    void setPlaylist();

private:
    QWidget* widget;
    QVBoxLayout* layout;
    QLabel* pageName;


    QLabel* music1;
    QLabel* music2;
    QLabel* music3;
    QLabel* music4;
    QLabel* music5;
};

#endif // PLAYLISTPAGE_HPP
