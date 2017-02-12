#include "mainwindow.h"
#include <QApplication>
#include "sorter.h"

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
//    std::vector<int> array = {1,4,6,8,5,2,0,7,9,3};
//    std::vector<int> pd = {5, 10};
//    Sorter s(Sorter::QUICK_SORT, Sorter::HEAP_SORT, array, pd);
//    s.start();

//    s.wait();

//    printf("time[5] = %.2f | %.2f\nswaps[5] = %i | %i\ncomp[5] = %i | %i\n", s.getTimes().first[0], s.getTimes().second[0], s.getSwaps().first[0], s.getSwaps().second[0], s.getComparisons().first[0], s.getComparisons().second[0]);

//    printArray(array);

//    if(!checkSorted(array)){
//        printf("Bad Sorting Method... BSM\n");
//        exit(-1);
//    }else{
//        printf("Good Sorting Method!\n");
//    }

    MainWindow w;
    w.show();

    return a.exec();
}
