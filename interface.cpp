#include "interface.h"

#include <QCoreApplication>
#include <QFile>

const int window_size_x = 500;
const int window_size_y = 600;
const int N = 4;
const int K = 2;
int lines = 0;

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
    info_line_text = new QLabel(QString::number(pow(2,K) - lines), this);
    QHBoxLayout *levelLayout3 = new QHBoxLayout;
    levelLayout3->addWidget(message_text);
    levelLayout3->addWidget(info_line_text);
    layout->addLayout(levelLayout3);

    connect(call_button, &QPushButton::clicked, this, &Interface::open_new_dialog);
}

void Interface::open_new_dialog(){
    Window *new_window = new Window(this);
    new_window->show();

    windows.push_back(new_window);
}

Interface::~Interface(){

}


