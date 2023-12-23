#include "interface.h"

#include <QCoreApplication>
#include <QFile>

const int window_size_x = 500;
const int window_size_y = 600;
const int N = 4;
const int K = 2;
int lines = pow(2, K);

void Interface::set_numbers(){
    QString appDirPath = QCoreApplication::applicationDirPath();
    appDirPath.remove("/debug");
    qDebug() << "Путь к каталогу приложения:" << appDirPath;
    QString filePath = appDirPath + "/numbers.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            numbers.push_back(line.toStdString());
            qDebug() << line;
        }

        file.close();
    } else {
        qDebug() << "Ошибка открытия файла:" << file.errorString();
    }
}

void Interface::set_abonents(QVBoxLayout *layout){
    for(int i = 0; i < pow(2, N) - 1; i++){
        QHBoxLayout *levelLayout = new QHBoxLayout;

        QLabel *text_abonent = new QLabel("",this);
        text_abonent->setText("Абонент " + QString::number(i + 1) + " :");

        QLabel *text_number = new QLabel("",this);
        text_number->setText(QString::fromStdString(numbers[i]));

        Abonent *new_abonent = new Abonent();
        new_abonent->set_number(numbers[i]);
        abonents.push_back(new_abonent);

        levelLayout->addWidget(text_abonent);
        levelLayout->addWidget(text_number);
        layout->addLayout(levelLayout);
    }
}

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Курсовая работа");
    setFixedSize(window_size_x, window_size_y);
    set_numbers();
    QVBoxLayout *layout = new QVBoxLayout(this);
    text1 = new QLabel("Номер, с которого звонят:", this);
    text2 = new QLabel("Номер, на который звонят:", this);
    number_call_from = new QLineEdit();
    number_call_to = new QLineEdit();
    call_button = new QPushButton("Вызов");
    QHBoxLayout *levelLayout1 = new QHBoxLayout;
    levelLayout1->addWidget(text1);
    levelLayout1->addWidget(number_call_from);
    layout->addLayout(levelLayout1);
    QHBoxLayout *levelLayout2 = new QHBoxLayout;
    levelLayout2->addWidget(text2);
    levelLayout2->addWidget(number_call_to);
    levelLayout2->addWidget(call_button);
    layout->addLayout(levelLayout2);
    set_abonents(layout);
    message_text = new QLabel("Выполните первый звонок", this);
    QHBoxLayout *levelLayout3 = new QHBoxLayout;
    levelLayout3->addWidget(message_text);
    layout->addLayout(levelLayout3);

    connect(call_button, &QPushButton::clicked, this, &Interface::open_new_dialog);
}

void Interface::open_new_dialog(){
    if (lines <= 0){
        message_text->setText("Все линии заняты!");
        return;
    }
    Connection *connection = new Connection(number_call_from->text().toStdString(), number_call_to->text().toStdString(), abonents);
    int status = connection->connection_status();
    if (!status){
        WindowFrom *new_window_from = new WindowFrom(this, connection->get_abonent_from(), &lines);
        new_window_from->show();
        WindowTo *new_window_to = new WindowTo(this, connection->get_abonent_to(), &lines, connection->get_abonent_to()->get_number());
        new_window_to->show();
        connect(new_window_from, &WindowFrom::sendMessage, new_window_to, &WindowTo::receiveMessage);
        connect(new_window_to, &WindowTo::sendMessage, new_window_from, &WindowFrom::receiveMessage);
        connect(new_window_to, &WindowTo::closeWindowsSignal, new_window_from, &WindowFrom::closeWindowsSlot);
        connect(new_window_from, &WindowFrom::closeWindowsSignal, new_window_to, &WindowTo::closeWindowsSlot);
        connect(new_window_to, &WindowTo::takeCall, new_window_from, &WindowFrom::confirmCall);
        lines--;
        message_text->setText("Номер набран");
    }else{
        switch (status) {
        case 1:
            message_text->setText("Неправильно набран номер!");
            break;
        case 2:
            message_text->setText("Нельзя позвонить самому себе!");
            break;
        case 3:
            message_text->setText("Линия занята!");
            break;
        default:
            break;
        }
    }
    delete connection;
//    windows.push_back(new_window);
}

Interface::~Interface(){

}


