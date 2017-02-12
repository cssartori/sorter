#ifndef __SORTALG_H__
#define __SORTALG_H__

#include <vector>

class SortAlg {
protected:
    int nSwaps; //number of swaps executed
    int nComparisons; //number of comparisons executed
    double time; //the ellapsed time


public:
    SortAlg();
    //pure virtual method (=0) to be implemented
    virtual std::vector<int> sort(std::vector<int> array) = 0;

    int getnSwaps();
    int getnComparisons();
    double getTime();

};

#endif // __SORTALG_H__
