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
#include "windowfrom.h"
#include "windowto.h"
#include "abonent.h"
#include "connection.h"

class Interface : public QWidget
{
    Q_OBJECT
    QLabel *text1, *text2;
    QLineEdit *number_call_from, *number_call_to;
    QPushButton *call_button; //звонок
    QLabel *message_text;//текст с сообщениями пользователю (снизу)
    std::vector<std::string> numbers;//список номеров
    std::vector<WindowFrom*> windows;// список диалоговых окон
    std::vector<Abonent*> abonents;// список абонентов

    void set_abonents(QVBoxLayout *layout);
    void set_numbers();
public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void open_new_dialog();
};

#endif // INTERFACE_H
