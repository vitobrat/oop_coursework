#include "windowfrom.h"
const int window_size_x = 350;
const int window_size_y = 160;

WindowFrom::WindowFrom(QWidget *parent, Abonent* abonent_from, int *lines) : QMainWindow(parent) {
    this->abonent_from = abonent_from;
    this->lines = lines;
    setFixedSize(window_size_x, window_size_y);
    setWindowTitle("Абонент:" + QString::fromStdString(abonent_from->get_number()) + "(вызывающий)");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Один общий вертикальный компоновщик для всех уровней
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Первый уровень (levelLayout1)
    QHBoxLayout *levelLayout1 = new QHBoxLayout();
    text = new QLabel("Ждем ответа вызываемого абонента...", centralWidget);
    levelLayout1->addWidget(text);
    layout->addLayout(levelLayout1);

    // Второй уровень (levelLayout2)
    QHBoxLayout *levelLayout2 = new QHBoxLayout();
    lineEdit = new QLineEdit(centralWidget);
    sendButton = new QPushButton("Сказать", centralWidget);
    levelLayout2->addWidget(lineEdit);
    levelLayout2->addWidget(sendButton);
    layout->addLayout(levelLayout2);

    // Третий уровень (levelLayout3)
    QHBoxLayout *levelLayout3 = new QHBoxLayout();
    closeButton = new QPushButton("Завершить набор", centralWidget);
    levelLayout3->addWidget(closeButton);
    layout->addLayout(levelLayout3);
    connect(sendButton, &QPushButton::clicked, [this]() {
        if(this->talk){
            emit sendMessage(lineEdit->text());
        }
    });
    connect(closeButton, &QPushButton::clicked, [this]() {
        emit closeWindowsSignal();
        this->abonent_from->set_status(0);
        close();
    });
}

void WindowFrom::receiveMessage(const QString &message)
{
    text->setText(message);
}

void WindowFrom::confirmCall()
{
    talk = true;
    abonent_from->set_status(2);
    text->setText("Разговор начат");
    closeButton->setText("Завершить разговор");
}

void WindowFrom::closeWindowsSlot(){
    this->abonent_from->set_status(0);
    (*lines)++;
    close();
}


