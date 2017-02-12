#ifndef __SORTER_H__
#define __SORTER_H__

#include <QThread>
#include <QObject>
#include "sortalg.h"

class Sorter: public QThread{
Q_OBJECT
public:
    Sorter(int algorithm1, int algorithm2, std::vector<int> array, const std::vector<int>& pointDistribution);
    std::pair< std::vector<double>, std::vector<double> > getTimes();
    std::pair< std::vector<int>, std::vector<int> > getSwaps();
    std::pair< std::vector<int>, std::vector<int> > getComparisons();

    //Sorting algorithms options
    const static int BUBBLE_SORT = 1;
    const static int INSERTION_SORT = 2;
    const static int SELECTION_SORT = 3;
    const static int QUICK_SORT = 4;
    const static int HEAP_SORT = 5;
    const static int MERGE_SORT = 6;
    const static int COUNTING_SORT = 7;

signals:
    void calcPercentChanged(double percent);

protected:
    void run();
private:
    int alg1, alg2;
    std::vector<int> array;
    std::vector<int> pointDistribution;
    std::vector<double> timeA1, timeA2;
    std::vector<int> swapsA1, swapsA2;
    std::vector<int> compA1, compA2;

    SortAlg* createSortAlg(int alg);
    std::vector<int>* createArray(std::vector<int>& origin, int size);
};

#endif // SORTER_H
