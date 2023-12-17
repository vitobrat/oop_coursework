#ifndef WINDOW_H
#define WINDOW_H
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

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr, Abonent* a1 = nullptr, Abonent* a2 = nullptr, int *lines = 0);

public slots:
    void close_window(Abonent* abonent_from, Abonent* abonent_to, int &lines);
};

#endif // WINDOW_H
