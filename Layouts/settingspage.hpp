#ifndef SETTINGSPAGE_HPP
#define SETTINGSPAGE_HPP

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class SettingsPage : public QWidget
{
    Q_OBJECT
public:
    explicit SettingsPage(QWidget *parent = nullptr);
    ~SettingsPage();

public:
    QVBoxLayout* getLayout() const;
    QWidget* getWidget() const;

private:
    void setSettings();

private:
    QWidget* widget;
    QVBoxLayout* layout;
    QLabel* pageName;
};

#endif // SETTINGSPAGE_HPP
