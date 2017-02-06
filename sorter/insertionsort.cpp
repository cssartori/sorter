#include "insertionsort.h"
#include <sys/timeb.h>

std::vector<int> InsertionSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    bool swapped;
    for(unsigned int i=1;i<array.size();i++){
        int j = i;
        swapped = false;
        while( j>0 && array[j-1] > array[j]){
            swapped = true;
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            this->nSwaps += 1;
            this->nComparisons += 1;
            j--;
        }
        this->nComparisons += 1;
        if(!swapped) break;
    }

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}
