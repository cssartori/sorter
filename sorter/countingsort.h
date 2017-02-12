#ifndef __COUNTINGSORT_H__
#define __COUNTINGSORT_H__

#include "sortalg.h"

class CountingSort: public SortAlg {
public:
    std::vector<int> sort(std::vector<int> array);

private:
    int maxElement(std::vector<int>* array);
};

#endif // __COUNTINGSORT_H__
