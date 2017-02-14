#ifndef __SORTER_SIGNALER_H__
#define __SORTER_SIGNALER_H__

#include <QObject>

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
