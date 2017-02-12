#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "sorter.h"
#include "constants.h"
#include <QComboBox>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_compareBtn_clicked();
    void on_calc_percent_update(double percent);

private:
    Ui::MainWindow *ui;
    Sorter* sorter = nullptr;

    int getAlgFromList(QComboBox *algList);
    std::vector<int> loadVector();


    const std::vector<std::string> SORT_NAMES = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Heap Sort", "Merge Sort", "Counting Sort"};
    const std::vector<int> SORT_CODES = {Sorter::BUBBLE_SORT, Sorter::INSERTION_SORT, Sorter::SELECTION_SORT, Sorter::QUICK_SORT, Sorter::HEAP_SORT, Sorter::MERGE_SORT, Sorter::COUNTING_SORT};
    const std::vector<std::string> VEC_NAMES = {ORD_VEC_MIN_MAX_NAME, ORD_VEC_MAX_MIN_NAME, RANDOM_VECTOR_NAME};
    const std::vector<int> VEC_CODES = {ORDERED_VECTOR_MIN_MAX, ORDERED_VECTOR_MAX_MIN, RANDOM_VECTOR};

    const static int CODE_ERROR = -1;
};

#endif // __MAINWINDOW_H__
