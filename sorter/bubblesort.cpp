#include "bubblesort.h"
#include <sys/timeb.h>

std::vector<int> BubbleSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    bool swapped;
    do{
        swapped = false;
        for(unsigned int i=1;i<array.size()-1;i++){
            if(array[i-1] > array[i]){
                swapped = true;
                this->nSwaps += 1;
                int temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
             }
             this->nComparisons += 1;
        }
    }while(swapped);

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}
