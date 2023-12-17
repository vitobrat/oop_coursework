#ifndef CONNECTION_H
#define CONNECTION_H

#include <Abonent.h>
#include <string>
#include <vector>

enum Errors{
    NO_MISTAKE = 0,
    WRONG_NUMBER, //Неправильно набран номер!
    SELF_CALL, //Нельзя позвонить самому себе!
    LINE_BUSY //Линия занята!
};

class Connection{
    Abonent *abonent_from, *abonent_to;
    Abonent* find_abonent(std::string number, std::vector<Abonent*>& abonents){
        for(int i = 0; i < abonents.size(); i++){
            if (abonents[i]->get_number() == number) return abonents[i];
        }
        return nullptr;
    }
public:
    Connection(std::string number_call_from, std::string number_call_to, std::vector<Abonent*>& abonents){
        abonent_from = find_abonent(number_call_from, abonents);
        abonent_to = find_abonent(number_call_to, abonents);
    }
    int connection_status(){
        if (abonent_to != nullptr && abonent_from != nullptr){
            if (abonent_from == abonent_to){
                return SELF_CALL;
            }
            if (abonent_from->get_status() == 0 && abonent_to->get_status() == 0){
                abonent_from->set_status(1);
                abonent_to->set_status(1);
                return NO_MISTAKE;
            }else{
                return LINE_BUSY;
            }
        }else{
            return WRONG_NUMBER;
        }
    }

    Abonent* get_abonent_from(){
        return abonent_from;
    }

    Abonent* get_abonent_to(){
        return abonent_to;
    }
    ~Connection(){};
};

#endif // CONNECTION_H
