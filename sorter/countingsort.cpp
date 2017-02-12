#include "countingsort.h"
#include <sys/timeb.h>

std::vector<int> CountingSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    int max = this->maxElement(&array);

    std::vector<int> ra(array.size(), 0); //return array
    std::vector<int> count(max+1, 0); //counting array

    //histogram for each element
    for(int i=0;i<array.size();i++)
        count[array[i]] += 1;

    for(int i=1;i<=max;i++)
        count[i] += count[i-1];

    for(int i=0;i<array.size();i++){
        ra[count[array[i]]-1] = array[i];
        count[array[i]] -= 1;
    }

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return ra;
}

int CountingSort::maxElement(std::vector<int>* array){
    int max = (*array)[0];
    for(int i=0;i<(*array).size();i++){
        if(max < (*array)[i])
            max = (*array)[i];
    }
    return max;
}
