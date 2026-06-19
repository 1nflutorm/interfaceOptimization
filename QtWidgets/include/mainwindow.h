#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVector>

typedef QVector< QVector<QPushButton*> > ButtonsGrid;
typedef QVector<QLabel*> Labels;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    void setupWindow();

    void createButtons(int startRow, int startCol);
    void createLabels(int hRow, int hStartCol,
                      int vStartRow, int vCol);
    void createHorizontalLabels(int row, int startCol);
    void createVerticalLabels(int startRow, int col);

private slots:
    void resizeSlot();

private:
    const int c_rowCount = 32;
    const int c_colCount = 32;
};
#endif // MAINWINDOW_H
