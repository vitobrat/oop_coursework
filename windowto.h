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
#include "abonent.h"

class WindowTo : public QMainWindow
{
    Q_OBJECT
public:
    explicit WindowTo(QWidget *parent = nullptr, Abonent* a1 = nullptr, int *lines = 0);

public slots:
    void receiveMessage(const QString &message);
    void closeWindowsSlot();
signals:
    void closeWindowsSignal();
    void sendMessage(const QString &message);

private:
    QLabel *text;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QPushButton *closeButton;
};
#endif // WINDOWTO_H
