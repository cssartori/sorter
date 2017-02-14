#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include <QMainWindow>
#include "sorter.h"
#include "constants.h"
#include "sortersignaler.h"
#include <QComboBox>
#include <vector>

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow Class is the main window GUI of the Sorter program. It holds all the interactions with the user
 * as well as the plotting of the final results.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_compareBtn_clicked();
    void on_signaler_percentChanged(double percent);
    void on_signaler_calcDone();
    void on_timeRBtn_clicked();
    void on_swapsRBtn_clicked();
    void on_comparisonRBtn_clicked();
    void on_cancelBtn_clicked();
    void on_clearGraphicOpt_triggered(bool);
    void on_saveTxtOpt_triggered(bool);
    void on_aboutOpt_triggered(bool);
    void on_exitOpt_triggered(bool);

private:
    Ui::MainWindow *ui;
    Sorter* sorter = nullptr;
    SorterSignaler *signaler = nullptr;
    int fileType;

    int getAlgFromList(QComboBox *algList);
    std::vector<int> loadVector();
    void setupGraphic(std::vector<double> a1, std::vector<double> a2, std::string a1Name, std::string a2Name, int option);
    void clearGraphic();

    const std::vector<std::string> SORT_NAMES = {"", "Bubble Sort", "Insertion Sort", "Selection Sort", "Quick Sort", "Heap Sort", "Merge Sort", "Counting Sort"};
    const std::vector<int> SORT_CODES = {Sorter::NO_SORT_METHOD, Sorter::BUBBLE_SORT, Sorter::INSERTION_SORT, Sorter::SELECTION_SORT, Sorter::QUICK_SORT, Sorter::HEAP_SORT, Sorter::MERGE_SORT, Sorter::COUNTING_SORT};
    const std::vector<std::string> VEC_NAMES = {ORD_VEC_MIN_MAX_NAME, ORD_VEC_MAX_MIN_NAME, RANDOM_VECTOR_NAME};
    const std::vector<int> VEC_CODES = {ORDERED_VECTOR_MIN_MAX, ORDERED_VECTOR_MAX_MIN, RANDOM_VECTOR};
    const std::string YLABEL_TIMES = "Execution Time (sec.)";
    const std::string YLABEL_SWAPS = "Num. of Swaps (x10^6)";
    const std::string YLABEL_COMPS = "Num. of Comparisons (x10^6)";
    const std::string XLABEL = "Vector Size";

    std::vector<double> xPoints;

    const static int CODE_ERROR = -1;
    const static int TIMES_PLOT_OPTION = 1;
    const static int SWAPS_PLOT_OPTION = 2;
    const static int COMPS_PLOT_OPTION = 3;
};

#endif // __MAINWINDOW_H__
