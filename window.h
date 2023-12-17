#ifndef WINDOW_H
#define WINDOW_H
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Устанавливаем заголовок для нового окна
        setWindowTitle("Новое окно");

        // Создаем кнопку в новом окне
        QPushButton *button = new QPushButton("Закрыть окно", this);
        connect(button, &QPushButton::clicked, this, &Window::close);

        // Устанавливаем кнопку в качестве центрального виджета
        setCentralWidget(button);
    }
};

#endif // WINDOW_H
