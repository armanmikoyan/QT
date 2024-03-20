#ifndef SEARCHBAR_HPP
#define SEARCHBAR_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QLineEdit>

class SearchBar : public QWidget
{
    Q_OBJECT
public:
    explicit SearchBar(QWidget *parent = nullptr);

private:
    QLineEdit* searchBar;
    QVBoxLayout* mainLayout;
    QWidget* mainWidget;
};

#endif // SEARCHBAR_HPP
