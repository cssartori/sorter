#ifndef __SORTER_SIGNALER_H__
#define __SORTER_SIGNALER_H__

#include <QObject>
/**
 * @brief The SorterSignaler class is responsible for emitting signals from the Sorter to the MainWindow, informing
 * that certain calculations have been done, errors and the overall progress.
 */
class SorterSignaler: public QObject {
    Q_OBJECT
signals:
    void percentChanged(double percent);
    void calcDone();

public:
    void updateCalcPercent(double percent){
        emit percentChanged(percent);
    }

    void calculationDone(){
        emit calcDone();
    }


};

#endif // __SORTER_SIGNALER_H__
