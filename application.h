#ifndef APPLICATION_H
#define APPLICATION_H


#include <QObject>
#include <QApplication>

#include "interface.h"

class Application : public QApplication
{
    Q_OBJECT
    Interface    *interface;

public:
    Application(int, char**);

};
#endif // APPLICATION_H
