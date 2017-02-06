#ifndef __INSERTIONSORT_H__
#define __INSERTIONSORT_H__

#include "sortalg.h"

class InsertionSort: public SortAlg {
public:
    std::vector<int> sort(std::vector<int> array);
};

#endif // __INSERTIONSORT_H__
