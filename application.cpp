#include "application.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc,argv)
{
    interface = new Interface();
    interface->show();
}
