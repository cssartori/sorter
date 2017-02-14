#include "sorter.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "countingsort.h"


Sorter::Sorter(int algorithm1, int algorithm2, std::vector<int> array, const std::vector<int>& pointDistribution, SorterSignaler *signaler) {
    this->alg1 = algorithm1;
    this->alg2 = algorithm2;
    this->array = array;
    this->pointDistribution = pointDistribution;
    this->signaler = signaler;
}

void Sorter::run(){
    SortAlg* alg1 = this->createSortAlg(this->alg1);
    SortAlg* alg2 = this->createSortAlg(this->alg2);

    std::vector<int>* array = nullptr;

    double pCalc = (99/pointDistribution.size());
    double percent = 0.0;

    for(int i=0;i<pointDistribution.size();i++){
        array = this->createArray(this->array, pointDistribution[i]);

        alg1->sort(*array);
        percent += pCalc;
        if(this->signaler != nullptr)
            this->signaler->updateCalcPercent(percent);

        alg2->sort(*array);
        percent += pCalc;
        if(this->signaler != nullptr)
            this->signaler->updateCalcPercent(percent);

        delete array;

        this->timeA1.push_back(alg1->getTime());
        this->swapsA1.push_back(alg1->getnSwaps());
        this->compA1.push_back(alg1->getnComparisons());

        this->timeA2.push_back(alg2->getTime());
        this->swapsA2.push_back(alg2->getnSwaps());
        this->compA2.push_back(alg2->getnComparisons());
    }

    if(this->signaler != nullptr)
        this->signaler->updateCalcPercent(100);

    if(this->signaler != nullptr)
        this->signaler->calculationDone();
}


std::vector<int>* Sorter::createArray(std::vector<int>& origin, int size){
    std::vector<int>* array = new std::vector<int>(size);

    for(int i=0;i<size;i++)
        (*array)[i] = origin[i];

    return array;
}

SortAlg* Sorter::createSortAlg(int alg){
    SortAlg* sa = nullptr;
    if(alg == Sorter::BUBBLE_SORT)
        sa = new BubbleSort();
    else if(alg == Sorter::INSERTION_SORT)
        sa = new InsertionSort();
    else if(alg == Sorter::SELECTION_SORT)
        sa = new SelectionSort();
    else if(alg == Sorter::QUICK_SORT)
        sa = new QuickSort();
    else if(alg == Sorter::HEAP_SORT)
        sa = new HeapSort();
    else if(alg == Sorter::MERGE_SORT)
        sa = new MergeSort();
    else if(alg == Sorter::COUNTING_SORT)
        sa = new CountingSort();

    return sa;
}

std::pair< std::vector<double>, std::vector<double> > Sorter::getTimes(){
    return std::make_pair(this->timeA1, this->timeA2);
}

std::pair< std::vector<double>, std::vector<double> > Sorter::getSwaps(){
    return std::make_pair(this->swapsA1, this->swapsA2);
}

std::pair< std::vector<double>, std::vector<double> > Sorter::getComparisons(){
    return std::make_pair(this->compA1, this->compA2);
}

std::pair<int, int> Sorter::getAlgs(){
    return std::make_pair(this->alg1, this->alg2);
}
