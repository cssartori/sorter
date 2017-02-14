#ifndef __INFOMESSAGE_H__
#define __INFOMESSAGE_H__

#include <QMessageBox>

class InfoMessage {
public:
    static void processRunningErrorMsg(QWidget *parent){
        QMessageBox msgBox;
        msgBox.critical(parent, QString::fromStdString(PROCESS_RUNNING_ERROR_TITLE), QString::fromStdString(PROCESS_RUNNING_ERROR_MSG));
    }

    static void algNotChosenErrorMsg(QWidget *parent){
        QMessageBox msgBox;
        msgBox.critical(parent, QString::fromStdString(ALG_NOT_CHOSEN_ERROR_TITLE), QString::fromStdString(ALG_NOT_CHOSEN_ERROR_MSG));
    }

    static void fileNotFoundErrorMsg(QWidget *parent, QString filename){
        QMessageBox msgBox;
        QString msg = QString::fromStdString(FILE_NOT_FOUND_ERROR_MSG).replace("#", filename);
        msgBox.critical(parent, QString::fromStdString(FILE_NOT_FOUND_ERROR_TITLE), msg);
    }

private:
    static constexpr const char* PROCESS_RUNNING_ERROR_TITLE = "Process Running!";
    static constexpr const char* ALG_NOT_CHOSEN_ERROR_TITLE = "Algorithm not chosen!";
    static constexpr const char* FILE_NOT_FOUND_ERROR_TITLE = "File not found!";

    static constexpr const char* PROCESS_RUNNING_ERROR_MSG = "A process is already running.\n Please, cancel the operation and try again.";
    static constexpr const char* ALG_NOT_CHOSEN_ERROR_MSG = "No algorithm was chosen in Algorithm 1 and 2. Please, choose at least one from the least to run the sorting.";
    static constexpr const char* FILE_NOT_FOUND_ERROR_MSG = "File # was not found.\n Please make sure it is found in the same directory as this program.";
};

#endif // __INFOMESSAGE_H__
