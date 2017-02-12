#include "mainwindow.h"
#include <QApplication>
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "mergesort.h"

bool checkSorted(std::vector<int> array){
    for(int i=0;i<array.size();i++){
        for(int j=i+1;j<array.size();j++){
            if(array[i] > array[j])
                return false;
        }
    }

    return true;
}

void printArray(std::vector<int> array){
    for(int i=0;i<array.size();i++)
        printf("%i, ", array[i]);

    printf("\n");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MergeSort s;
    std::vector<int> array = {1,4,6,8,5,2,0,7,9,3};
    array = s.sort(array);

    printArray(array);

    if(!checkSorted(array)){
        printf("Bad Sorting Method... BSM\n");
        exit(-1);
    }else{
        printf("Good Sorting Method!\n");
    }

    MainWindow w;
    w.show();

    return a.exec();
}
