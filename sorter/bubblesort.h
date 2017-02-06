#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#include "sortalg.h"

class BubbleSort: public SortAlg {
public:
    std::vector<int> sort(std::vector<int> array);
};

#endif // __BUBBLESORT_H__
