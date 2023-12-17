#ifndef INTERFACE_H
#define INTERFACE_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <vector>
#include "window.h"

class Interface : public QWidget
{
    Q_OBJECT
    QLabel *text1, *text2;
    QLineEdit *number_call_from, *number_call_to;
    QPushButton *call_button; //звонок
    QLabel *message_text;//текст с сообщениями пользователю (снизу)
    QLabel *info_line_text;//сколько осталось незанятых линий
    std::vector<std::string> numbers;
    std::vector<Window*> windows;

    void set_abonents(QVBoxLayout *layout);
    void set_numbers();
public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void open_new_dialog();
};

#endif // INTERFACE_H
