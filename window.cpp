#include "window.h"

Window::Window(QWidget *parent, Abonent* abonent_from, Abonent* abonent_to, int *lines) : QMainWindow(parent) {
    // Устанавливаем заголовок для нового окна
    setWindowTitle("Вызов");
    setFixedSize(500, 500);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QLabel *text1 = new QLabel("Номер, с которого звонят:" + QString::fromStdString(abonent_from->get_number()), centralWidget);
    QLabel *text2 = new QLabel("Номер, на который звонят:" + QString::fromStdString(abonent_to->get_number()), centralWidget);
    layout->addWidget(text1);
    layout->addWidget(text2);
//    number_call_from = new QLineEdit();
//    number_call_to = new QLineEdit();
//    call_button = new QPushButton("Вызов");
//    QHBoxLayout *levelLayout1 = new QHBoxLayout;
//    levelLayout1->addWidget(text1);
//    layout->addLayout(levelLayout1);
//    QHBoxLayout *levelLayout2 = new QHBoxLayout;
//    levelLayout2->addWidget(text2);
//    layout->addLayout(levelLayout2);
//    QHBoxLayout *levelLayout3 = new QHBoxLayout;
    QPushButton *button = new QPushButton("Закрыть окно", centralWidget);
    layout->addWidget(button);
    connect(button,&QPushButton::clicked, [=](){
        close_window(abonent_from, abonent_to, *lines);
    });
}

void Window::close_window(Abonent* abonent_from, Abonent* abonent_to, int &lines){
    lines++;
    abonent_from->set_status(0);
    abonent_to->set_status(0);
    close();
}
