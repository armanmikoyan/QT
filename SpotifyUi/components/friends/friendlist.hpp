#ifndef FRIENDLIST_HPP
#define FRIENDLIST_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QComboBox>

class FriendList : public QWidget
{
    Q_OBJECT
public:
    explicit FriendList(QWidget *parent = nullptr);
private:
    QWidget* friendFactory();
    void setFriends();

private:
    QVBoxLayout* mainLayout;
    QWidget* mainWidget;
};

#endif // FRIENDLIST_HPP
