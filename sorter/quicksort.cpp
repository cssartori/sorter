#include "quicksort.h"
#include <sys/timeb.h>
#include <stack>


std::vector<int> QuickSort::sort(std::vector<int> array){
    timeb start, end;
    ftime(&start); // start timer

    array = this->recSort(array, 0, array.size()-1);

    ftime(&end); // end timer
    this->time = (end.time - start.time)*1000;
    this->time=(this->time+end.millitm-start.millitm)/1000;

    return array;
}

std::vector<int> QuickSort::recSort(std::vector<int> array, int fst, int lst){
    std::stack< std::pair<int,int> > stk;
    stk.push(std::make_pair(fst, lst));

    do{
        fst = stk.top().first;
        lst = stk.top().second;
        stk.pop();
        int pivot = this->partitioning(array, fst, lst);
        if(pivot+1 < lst)
            stk.push(std::make_pair(pivot+1, lst));
        else if(pivot-1 > fst)
             stk.push(std::make_pair(fst, pivot-1));
    }while(stk.size() > 0);


}


int QuickSort::partitioning(std::vector<int> array, int fst, int lst){

}
