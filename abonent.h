#ifndef ABONENT_H
#define ABONENT_H

#include <string>


//status 0 - готов, status 1 - вызов, status 2 - разговор
class Abonent
{
private:
    std::string number;
    //по умолчанию абонент готов
    int status = 0;
public:
    Abonent();
    //инкапсуляция для number и status
    void set_number(std::string);
    void set_status(int);
    std::string get_number();
    int get_status();
};

#endif // ABONENT_H
