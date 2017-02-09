#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

#include "sortalg.h"

class HeapSort: public SortAlg{
public:
    std::vector<int> sort(std::vector<int> array);

private:
    std::vector<int>* heapify(std::vector<int> *array, int i, int heapSize);
    std::vector<int>* buildHeap(std::vector<int> *array);
    //Returns the index of the left child of node i
    int leftChild(int i);
    //Returns the index of the right child of node i
    int rightChild(int i);
};

#endif // __HEAPSORT_H__
