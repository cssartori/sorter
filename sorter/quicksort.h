#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "sortalg.h"

class QuickSort: public SortAlg {
public:
     std::vector<int> sort(std::vector<int> array);
private:
     //Iterative QuickSort implementation
     std::vector<int>* iterSort(std::vector<int> *array, int low, int high);
     int partition(std::vector<int> *array, int low, int high);
     //Chooses pivot using the Median rule
     int getPivot(std::vector<int>& array, int low, int high);
};

#endif // __QUICKSORT_H__
