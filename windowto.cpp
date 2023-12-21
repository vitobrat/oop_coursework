#include "windowto.h"

const int window_size_x = 350;
const int window_size_y = 160;

WindowTo::WindowTo(QWidget *parent, Abonent* abonent_to, int *lines, std::string num) : QMainWindow(parent)
{
    this->abonent_to = abonent_to;
    this->lines = lines;
    setFixedSize(window_size_x, window_size_y);
    setWindowTitle("Абонент:" + QString::fromStdString(abonent_to->get_number()));
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Один общий вертикальный компоновщик для всех уровней
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Первый уровень (levelLayout1)
    QHBoxLayout *levelLayout1 = new QHBoxLayout();
    text = new QLabel("Вам звонит абонент:" + QString::fromStdString(num), centralWidget);
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
    closeButton = new QPushButton("Отклонить", centralWidget);
    take_call = new QPushButton("Принять", centralWidget);
    levelLayout3->addWidget(take_call);
    levelLayout3->addWidget(closeButton);
    layout->addLayout(levelLayout3);
    connect(sendButton, &QPushButton::clicked, [this]() {
        if(this->talk){
            emit sendMessage(lineEdit->text());
        }
    });
    connect(closeButton, &QPushButton::clicked, [this]() {
        emit closeWindowsSignal();
        this->abonent_to->set_status(0);
        close();
    });
    connect(take_call, &QPushButton::clicked, [this]() {
        emit takeCall();
        this->abonent_to->set_status(2);
        this->talk = true;
        this->text->setText("Разговор начат");
        this->take_call->setVisible(false);
        closeButton->setText("Завершить разговор");
    });
}

void WindowTo::receiveMessage(const QString &message)
{
    text->setText(message);
}

void WindowTo::closeWindowsSlot(){
    this->abonent_to->set_status(0);
    (*lines)++;
    close();
}


