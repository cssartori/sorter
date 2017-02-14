#include "sortalg.h"

SortAlg::SortAlg(){
    this->nComparisons = 0;
    this->nSwaps = 0;
    this->time = 0;
}

unsigned int SortAlg::getnSwaps(){
    return this->nSwaps;
}

unsigned int SortAlg::getnComparisons(){
    return this->nComparisons;
}

double SortAlg::getTime(){
    return this->time;
}
