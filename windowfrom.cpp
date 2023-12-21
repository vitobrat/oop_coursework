#include "windowfrom.h"

WindowFrom::WindowFrom(QWidget *parent, Abonent* abonent_from, int *lines) : QMainWindow(parent) {
    setWindowTitle("Абонент:" + QString::fromStdString(abonent_from->get_number()) + "(вызывающий)");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QHBoxLayout *levelLayout1 = new QHBoxLayout(centralWidget);
    text = new QLabel(centralWidget);
    lineEdit = new QLineEdit(centralWidget);
    sendButton = new QPushButton("Send", centralWidget);
    closeButton = new QPushButton("Close", centralWidget);
    levelLayout1->addWidget(text);
    levelLayout1->addWidget(lineEdit);
    levelLayout1->addWidget(sendButton);
    levelLayout1->addWidget(closeButton);
    connect(sendButton, &QPushButton::clicked, [this]() {
        emit sendMessage(lineEdit->text());
    });
    connect(closeButton, &QPushButton::clicked, [this]() {
        emit closeWindowsSignal();
        close();
    });
}

void WindowFrom::receiveMessage(const QString &message)
{
    text->setText(message);
}

void WindowFrom::closeWindowsSlot(){
    close();
}


