#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "ui_mainwindow.h"
#include <QtGui>
#include <qwt_plot.h>
#include <stdio.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);

    
private slots:
    void on_btn_compara_clicked();

    void on_rtroca_clicked();

    void on_rtempo_clicked();

    void on_rcomp_clicked();

    void clear_Plot();

    void Save_as_txt();

    void about_window_info();

private:
    Ui::MainWindow *ui;
    void setupPlot(double *y1, double *y2);

};

#endif // MAINWINDOW_H
