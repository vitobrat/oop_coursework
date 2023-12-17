#include "abonent.h"

Abonent::Abonent()
{

}

void Abonent::set_number(std::string number){
    this->number = number;
}

void Abonent::set_status(int status){
    this->status = status;
}

std::string Abonent::get_number(){
    return this->number;
}

int Abonent::get_status(){
    return this->status;
}
