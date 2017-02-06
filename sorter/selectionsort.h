#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

#include "sortalg.h"

class SelectionSort: public SortAlg {
public:
    std::vector<int> sort(std::vector<int> array);
};

#endif // __SELECTIONSORT_H__
