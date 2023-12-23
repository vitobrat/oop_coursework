#ifndef WINDOWTO_H
#define WINDOWTO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractButton>
#include <QRadioButton>
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <vector>
#include <QTextEdit>
#include <string.h>
#include "abonent.h"

class WindowTo : public QMainWindow
{
    Q_OBJECT
    int *lines;
    Abonent* abonent_to;
    bool talk = false;
public:
    explicit WindowTo(QWidget *parent = nullptr, Abonent* a1 = nullptr, int *lines = 0, std::string num = "");

public slots:
    void receiveMessage(const QString &message);
    void closeWindowsSlot();
signals:
    void closeWindowsSignal();
    void sendMessage(const QString &message);
    void takeCall();

private:
    QLabel *text;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QPushButton *closeButton;
    QPushButton *take_call;
};
#endif // WINDOWTO_H
