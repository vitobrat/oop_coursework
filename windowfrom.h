#ifndef WINDOWFROM_H
#define WINDOWFROM_H
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
#include "abonent.h"

class WindowFrom : public QMainWindow
{
    Q_OBJECT
public:
    explicit WindowFrom(QWidget *parent = nullptr, Abonent* a1 = nullptr, int *lines = 0);

signals:
    void sendMessage(const QString &message);
    void closeWindowsSignal();
public slots:
    void closeWindowsSlot();
    void receiveMessage(const QString &message);

private:
    QLabel *text;
    QLineEdit *lineEdit;
    QPushButton *sendButton;
    QPushButton *closeButton;
};

#endif // WINDOWFROM_H
