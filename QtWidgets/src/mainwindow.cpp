#include "../include/mainwindow.h"

#include <chrono>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto start = std::chrono::high_resolution_clock::now();

    setupWindow();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    qDebug().noquote() << "Время выполнения конструктора: " << duration.count();
}

void MainWindow::setupWindow()
{
    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(new QGridLayout(centralWidget));
    setCentralWidget(centralWidget);

    createLabels(0, 1, 1, 0);
    createButtons(1, 1);
}

void MainWindow::createButtons(int startRow, int startCol)
{
    for(int i = startRow; i < startRow + c_rowCount; i++)
    {
        for(int j = startCol; j < startCol + c_colCount; j++)
        {
            QPushButton* btn = new QPushButton(centralWidget());
            btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
            btn->setCursor(Qt::PointingHandCursor);
            connect(btn, &QPushButton::clicked, this, &MainWindow::resizeSlot);

            QGridLayout* layout = dynamic_cast<QGridLayout*>(centralWidget()->layout());
            layout->addWidget(btn, i, j, 1, 1);
        }
    }
}

void MainWindow::createLabels(int hRow, int hStartCol,
                              int vStartRow, int vCol)
{
    createHorizontalLabels(hRow, hStartCol);
    createVerticalLabels(vStartRow, vCol);
}

void MainWindow::createHorizontalLabels(int row, int startCol)
{
    for(int i = startCol; i < startCol + c_colCount; i++)
    {
        QLabel* label = new QLabel(QString::number(i), centralWidget());
        label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        QGridLayout* layout = dynamic_cast<QGridLayout*>(centralWidget()->layout());
        layout->addWidget(label, row, i, 1, 1, Qt::AlignCenter);
    }
}

void MainWindow::createVerticalLabels(int startRow, int col)
{
    for(int i = startRow; i < startRow + c_rowCount; i++)
    {
        QLabel* label = new QLabel(QString::number(i), centralWidget());
        label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

        QGridLayout* layout = dynamic_cast<QGridLayout*>(centralWidget()->layout());
        layout->addWidget(label, i, col, 1, 1, Qt::AlignCenter);
    }
}

void MainWindow::resizeSlot()
{
    auto start = std::chrono::high_resolution_clock::now();

    resize(width() + 100, height()+ 100);
    QApplication::processEvents();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    qDebug().noquote() << "Время выполнения изменения размера окна: " << duration.count();
}
