#include "quicksort.h"
#include <sys/timeb.h>
#include <stack>
#include <cstdio>

std::vector<int> QuickSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    this->iterSort(&array, 0, array.size()-1);

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}

//Iterative QuickSort implementation
std::vector<int>* QuickSort::iterSort(std::vector<int> *array, int low, int high){
    std::stack< std::pair<int,int> > stk;
    stk.push(std::make_pair(low, high));

    do{
        low = stk.top().first;
        high = stk.top().second;
        stk.pop();
        int pivot = this->partition(array, low, high);
        if(pivot+1 < high)
            stk.push(std::make_pair(pivot+1, high));
        if(pivot-1 > low)
            stk.push(std::make_pair(low, pivot-1));
    }while(stk.size() > 0);

    return array;
}

int QuickSort::partition(std::vector<int> *array, int low, int high){
    int pivot = this->getPivot(*array, low, high); //pivot index
    int k=low, j=high; //two indexes to read the array (k for values less than pivot, and j for values bigger than pivot)

    while(k < pivot || j > pivot){
        if((*array)[k] > (*array)[j]){
            int temp = (*array)[k];
            (*array)[k] = (*array)[j];
            (*array)[j] = temp;
            this->nSwaps+=1;
            if(j == pivot) pivot = k;
            else if(k == pivot) pivot = j;
        }
        this->nComparisons+=1;
        if(k < pivot) k++;
        if(j > pivot) j--;
    }

    return pivot; //return the pivot index
}

//Chooses pivot using the Median rule
int QuickSort::getPivot(std::vector<int>& array, int low, int high){
    if(high - low < 3) //less than 3 elements in sub-array
        return high;

    int m = (low+high)/2;

    if(array[low] <= array[m] && array[m] <= array[high])
        return m;
    else if(array[m] <= array[low] && array[low] <= array[high])
        return low;
    else if(array[high] <= array[low] && array[low] <= array[m])
        return low;
    else
        return high;
}
