#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "sortalg.h"

class MergeSort: public SortAlg{
public:
    std::vector<int> sort(std::vector<int> array);

private:
    std::vector<int>* recSort(std::vector<int>* array, int left, int right);
    std::vector<int>* merge(std::vector<int>* array, int ls, int le, int rs, int re);
};

#endif // __MERGESORT_H__
