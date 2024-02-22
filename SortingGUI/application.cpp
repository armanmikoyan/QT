#include "application.hpp"

application::application(Ui::MainWindow *_ptr, QObject *parent)
    : ui{_ptr}
    , QObject{parent}
{
    connections();
}

void application::connections()
{
    connect(ui->file_selector, &QPushButton::clicked, this, &application::onFileSelectorClicked);


    connect(ui->bubble_strategy, &QRadioButton::clicked, this, &application::onStrategyClicked);
    connect(ui->selection_strategy, &QRadioButton::clicked, this, &application::onStrategyClicked);
    connect(ui->insertion_strategy, &QRadioButton::clicked, this, &application::onStrategyClicked);


    connect(ui->sort, &QPushButton::clicked, this, &application::onSortClicked);
}


void application::onFileSelectorClicked()
{
    file = QFileDialog::getOpenFileName(nullptr, "Open File", QDir::homePath() + "/qt_lessons/file_for_sorting", "All Files (*)");
    QFileInfo fileInfo(file);
    QString name = fileInfo.fileName();

    ui->selected_file->setText("Selected File: " + name);
}

void application::onStrategyClicked()
{
    QRadioButton *clickedButton = qobject_cast<QRadioButton*>(sender());
    if (clickedButton == ui->bubble_strategy)
    {
        strategy = _strategy::bubble;
        ui->selected_algorithm->setText("Selected Algorithm: Bubble Sort");

        if (algo)
        {
            delete algo;
        }
        algo = new Bubble(array, this);
    }
    else if (clickedButton == ui->selection_strategy)
    {
        strategy = _strategy::selection;
        ui->selected_algorithm->setText("Selected Algorithm: Selection Sort");
        if (algo)
        {
            delete algo;
        }
        algo = new Selection(array, this);
    }
    else if (clickedButton == ui->insertion_strategy)
    {
        strategy = _strategy::insertion;
        ui->selected_algorithm->setText("Selected Algorithm: Insertion Sort");
        if (algo)
        {
            delete algo;
        }
        algo = new Insertion(array, this);
    }
    else
    {
        strategy = _strategy::none;
    }
}

void application::onSortClicked()
{
    if (strategy == _strategy::none)
    {
        QMessageBox::warning(nullptr, "Select", "Select Algorithm");
        return;
    }
    else if (file.isEmpty())
    {
        QMessageBox::warning(nullptr, "Select", "Select file");
        return;
    }

    fileHandler f(file, this);
    if (f.readFile(array) == -1)
    {
        ui->status->setText("Error. Incorecct content of file");
        return;
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    algo->sort();

    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    QString nano = QString::number(elapsedTime.count());
    ui->status->setText("Success. File is sorted in " + nano + " nanoseconds.");

    f.writeToFile(array);
    array.clear();

}
