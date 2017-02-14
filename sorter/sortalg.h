#ifndef __SORTALG_H__
#define __SORTALG_H__

#include <vector>

/**
 * The SortAlg class is an interface of Sorting Algorithms. It contains the basic information
 * all sorts store, such as time, number of swaps and comparisons executed. Also, its virtual
 * method 'sort' must be implemented by the child class, in order to execute is particular sort
 * method.
 */

class SortAlg {
protected:
    unsigned int nSwaps; //number of swaps executed
    unsigned int nComparisons; //number of comparisons executed
    double time; //the ellapsed time

public:
    SortAlg();
    //pure virtual method (=0) to be implemented
    virtual std::vector<int> sort(std::vector<int> array) = 0;

    unsigned int getnSwaps();
    unsigned int getnComparisons();
    double getTime();

};

#endif // __SORTALG_H__
