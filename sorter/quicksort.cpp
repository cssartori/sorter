#include "quicksort.h"
#include <sys/timeb.h>
#include <stack>
#include <cstdio>

std::vector<int> QuickSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    array = this->iterSort(array, 0, array.size()-1);

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}

//Iterative QuickSort implementation
std::vector<int> QuickSort::iterSort(std::vector<int> array, int fst, int lst){
    std::stack< std::pair<int,int> > stk;
    stk.push(std::make_pair(fst, lst));

    do{
        fst = stk.top().first;
        lst = stk.top().second;
        stk.pop();
        int pivot = this->partition(&array, fst, lst);
        if(pivot+1 < lst)
            stk.push(std::make_pair(pivot+1, lst));
        else if(pivot-1 > fst)
            stk.push(std::make_pair(fst, pivot-1));
    }while(stk.size() > 0);

    return array;
}

int QuickSort::partition(std::vector<int> *array, int fst, int lst){
    int pivot = this->getPivot(*array, fst, lst); //pivot index
    int k=fst, j=lst; //two indexes to read the array (k for values less than pivot, and j for values bigger than pivot)

    printf("Array from %i to %i\nNot Ordered - %i:\n", fst, lst, pivot);
    for(int i=fst;i<=lst;i++){
        printf("%i, ", (*array)[i]);
    }



    while(k < pivot || j > pivot){
        if((*array)[k] > (*array)[j]){
            int temp = (*array)[k];
            (*array)[k] = (*array)[j];
            (*array)[j] = temp;
            this->nSwaps+=1;
            this->nComparisons+=1;
            if(j == pivot) pivot = k;
            else if(k == pivot) pivot = j;
        }
        if(k < pivot) k++;
        if(j > pivot) j--;
        printf("Pivot now is %i\n", pivot);
    }
   printf("\nOrdered - %i:\n", pivot);
    for(int i=fst;i<=lst;i++){
        printf("%i, ", (*array)[i]);
    }

    printf("\n");
    return pivot; //return the pivot index
}

//Chooses pivot using the Median rule
int QuickSort::getPivot(std::vector<int>& array, int fst, int lst){
    if(lst - fst < 3) //less than 3 elements in sub-array
        return lst;

    int m = (fst+lst)/2;

    if(array[fst] <= array[m] && array[m] <= array[lst])
        return m;
    else if(array[m] <= array[fst] && array[fst] <= array[lst])
        return fst;
    else
        return lst;
}
