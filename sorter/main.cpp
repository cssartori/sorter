#include "mainwindow.h"
#include <QApplication>
#include "bubblesort.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BubbleSort bs;
    std::vector<int> array(100,0);
    bs.sort(array);
    MainWindow w;
    w.show();

    return a.exec();
}
