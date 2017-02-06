#include "selectionsort.h"
#include <sys/timeb.h>

std::vector<int> SelectionSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    for(unsigned int i=0;i<array.size()-1;i++){
        int minIndex = i;
        for(unsigned int j=i+1;j<array.size();j++){
             if(array[j] < array[minIndex])
                 minIndex = j;

             this->nComparisons += 1;
         }

         if(i != minIndex){
             int temp = array[minIndex];
             array[minIndex] = array[i];
             array[i] = temp;
            this->nSwaps += 1;
         }
     }

     ftime(&end); // end timer
     this->time = (end.time - start.time)*1000;
     this->time=(this->time+end.millitm-start.millitm)/1000;

     return array;
}
