#include "heapsort.h"
#include <sys/timeb.h>


std::vector<int> HeapSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    this->buildHeap(&array);
    int heapSize = array.size()-1;
    for(int i=heapSize;i>=1;i++){
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapSize--;
        this->heapify(&array, 0, heapSize);
    }

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}

std::vector<int>* HeapSort::heapify(std::vector<int> *array, int i, int heapSize){
    int r = this->rightChild(i);
    int l = this->leftChild(i);
    int maxi = i; //index of the largest element in the heap

    if(r <= heapSize && (*array)[r] > (*array)[maxi])
        maxi = r;
    if(l <= heapSize && (*array)[l] > (*array)[maxi])
        maxi = l;
    this->nComparisons+=2;

    if(maxi != i){
        int temp = (*array)[maxi];
        (*array)[maxi] = (*array)[i];
        (*array)[i] = temp;
        this->nSwaps+=1;
        array = this->heapify(array, maxi, heapSize);
    }

    return array;
}

std::vector<int>* HeapSort::buildHeap(std::vector<int> *array){
    for(int parent = (*array).size(); parent >= 0 ; parent--){
        array = this->heapify(array, parent, (*array).size());
    }
    return array;
}

//Returns the index of the left child of node i
int HeapSort::leftChild(int i){
    return 2*i+1;
}

//Returns the index of the right child of node i
int HeapSort::rightChild(int i){
    return 2*i+2;
}
