#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "sortalg.h"

class QuickSort: public SortAlg {
public:
     std::vector<int> sort(std::vector<int> array);
private:
     std::vector<int> recSort(std::vector<int> array, int fst, int lst);
     int partitioning(std::vector<int> array, int fst, int lst);
};

#endif // __QUICKSORT_H__
