#include "sortalg.h"

SortAlg::SortAlg(){
    this->nComparisons = 0;
    this->nSwaps = 0;
    this->time = 0;
}

int SortAlg::getnSwaps(){
    return this->nSwaps;
}

int SortAlg::getnComparisons(){
    return this->nComparisons;
}

double SortAlg::getTime(){
    return this->time;
}
