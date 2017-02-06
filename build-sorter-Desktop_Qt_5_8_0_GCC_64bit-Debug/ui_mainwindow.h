/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *exitAction;
    QAction *clearPlot;
    QAction *saveastxt;
    QAction *exitAction_2;
    QAction *especs;
    QAction *let_esp;
    QAction *about_2;
    QWidget *centralWidget;
    QComboBox *alglist_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btn_compara;
    QComboBox *vetlist;
    QLabel *label_3;
    QGroupBox *graphicGroup;
    QRadioButton *timeRBtn;
    QRadioButton *swapsRBtn;
    QRadioButton *compareRBtn;
    QCustomPlot *widget;
    QComboBox *alglist_3;
    QProgressBar *progressBar;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menuOp_es;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(602, 451);
        MainWindow->setMinimumSize(QSize(602, 451));
        MainWindow->setMaximumSize(QSize(602, 451));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QStringLiteral("exitAction"));
        exitAction->setCheckable(false);
        clearPlot = new QAction(MainWindow);
        clearPlot->setObjectName(QStringLiteral("clearPlot"));
        clearPlot->setShortcutContext(Qt::WidgetShortcut);
        saveastxt = new QAction(MainWindow);
        saveastxt->setObjectName(QStringLiteral("saveastxt"));
        exitAction_2 = new QAction(MainWindow);
        exitAction_2->setObjectName(QStringLiteral("exitAction_2"));
        especs = new QAction(MainWindow);
        especs->setObjectName(QStringLiteral("especs"));
        let_esp = new QAction(MainWindow);
        let_esp->setObjectName(QStringLiteral("let_esp"));
        about_2 = new QAction(MainWindow);
        about_2->setObjectName(QStringLiteral("about_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        alglist_2 = new QComboBox(centralWidget);
        alglist_2->setObjectName(QStringLiteral("alglist_2"));
        alglist_2->setGeometry(QRect(160, 350, 101, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 330, 121, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 330, 121, 16));
        btn_compara = new QPushButton(centralWidget);
        btn_compara->setObjectName(QStringLiteral("btn_compara"));
        btn_compara->setGeometry(QRect(480, 340, 101, 81));
        vetlist = new QComboBox(centralWidget);
        vetlist->setObjectName(QStringLiteral("vetlist"));
        vetlist->setGeometry(QRect(300, 350, 161, 22));
        vetlist->setMaxVisibleItems(3);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 330, 121, 16));
        graphicGroup = new QGroupBox(centralWidget);
        graphicGroup->setObjectName(QStringLiteral("graphicGroup"));
        graphicGroup->setGeometry(QRect(20, 10, 561, 301));
        timeRBtn = new QRadioButton(graphicGroup);
        timeRBtn->setObjectName(QStringLiteral("timeRBtn"));
        timeRBtn->setGeometry(QRect(10, 40, 82, 17));
        timeRBtn->setCheckable(true);
        timeRBtn->setChecked(false);
        swapsRBtn = new QRadioButton(graphicGroup);
        swapsRBtn->setObjectName(QStringLiteral("swapsRBtn"));
        swapsRBtn->setGeometry(QRect(10, 90, 82, 17));
        compareRBtn = new QRadioButton(graphicGroup);
        compareRBtn->setObjectName(QStringLiteral("compareRBtn"));
        compareRBtn->setGeometry(QRect(10, 150, 121, 17));
        widget = new QCustomPlot(graphicGroup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 30, 401, 261));
        alglist_3 = new QComboBox(centralWidget);
        alglist_3->setObjectName(QStringLiteral("alglist_3"));
        alglist_3->setGeometry(QRect(20, 350, 101, 22));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 400, 321, 23));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 380, 181, 16));
        MainWindow->setCentralWidget(centralWidget);
        graphicGroup->raise();
        alglist_2->raise();
        label->raise();
        label_2->raise();
        btn_compara->raise();
        vetlist->raise();
        label_3->raise();
        alglist_3->raise();
        progressBar->raise();
        label_4->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 22));
        menuOp_es = new QMenu(menuBar);
        menuOp_es->setObjectName(QStringLiteral("menuOp_es"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuOp_es->menuAction());
        menuOp_es->addAction(clearPlot);
        menuOp_es->addAction(saveastxt);
        menuOp_es->addAction(about_2);
        menuOp_es->addAction(exitAction_2);

        retranslateUi(MainWindow);

        vetlist->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        exitAction->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        clearPlot->setText(QApplication::translate("MainWindow", "Limpar Gr\303\241fico", Q_NULLPTR));
        clearPlot->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
        saveastxt->setText(QApplication::translate("MainWindow", "Salvar em Texto...", Q_NULLPTR));
        saveastxt->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
        exitAction_2->setText(QApplication::translate("MainWindow", "Sair", Q_NULLPTR));
        exitAction_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        especs->setText(QApplication::translate("MainWindow", "Especifica\303\247\303\265es", Q_NULLPTR));
        especs->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", Q_NULLPTR));
        let_esp->setText(QApplication::translate("MainWindow", "LET Especial #0", Q_NULLPTR));
        let_esp->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        about_2->setText(QApplication::translate("MainWindow", "Sobre...", Q_NULLPTR));
        about_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        alglist_2->clear();
        alglist_2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "1. Bubblesort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2. Quicksort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3. Insertionsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4. Selectionsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5. Heapsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6. Mergesort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7. Countingsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8. Bucketsort", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        alglist_2->setToolTip(QApplication::translate("MainWindow", "Algoritmo 2 a ser comparado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Algoritmo 1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Algoritmo 2:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btn_compara->setToolTip(QApplication::translate("MainWindow", "Comparar algoritmos selecionados", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btn_compara->setText(QApplication::translate("MainWindow", "Comparar", Q_NULLPTR));
        vetlist->clear();
        vetlist->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. Vetor ordem crescente", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2. Vetor ordem decrescente", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3. Vetor aleat\303\263rio", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        vetlist->setToolTip(QApplication::translate("MainWindow", "Ordena\303\247\303\243o do vetor a ser ordenado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "Formato do vetor:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        graphicGroup->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        graphicGroup->setTitle(QApplication::translate("MainWindow", "Graphic", Q_NULLPTR));
        timeRBtn->setText(QApplication::translate("MainWindow", "Time", Q_NULLPTR));
        swapsRBtn->setText(QApplication::translate("MainWindow", "Swaps", Q_NULLPTR));
        compareRBtn->setText(QApplication::translate("MainWindow", "Comparissons", Q_NULLPTR));
        alglist_3->clear();
        alglist_3->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "1. Bubblesort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2. Quicksort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3. Insertionsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4. Selectionsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5. Heapsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6. Mergesort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7. Countingsort", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8. Bucketsort", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        alglist_3->setToolTip(QApplication::translate("MainWindow", "Algoritmo 1 a ser comparado", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "Porcentagem de c\303\241lculos realizada:", Q_NULLPTR));
        menuOp_es->setTitle(QApplication::translate("MainWindow", "Op\303\247\303\265es", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
