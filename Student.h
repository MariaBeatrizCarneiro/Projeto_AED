#ifndef LOADCLASSES_H_STUDENT_H
#define LOADCLASSES_H_STUDENT_H
#include <string>
#include <list>
#include "UcTurma.h"

class Student {
private:
    std::string mecaNumber_;
    std::string name_;
    std::list<UcTurma> turm_;

public:
    //Student Constructor
    Student();
    Student(std::string mecaNumber, std::string name, std::list<UcTurma> turm, std::string order);

    //Student Setters
    void set_mecaNumber(std::string mecaNumber);
    void set_name(std::string name);
    void set_turm(std::list<UcTurma> turm);
    void set_order(std::string order);

    //Student Getters
    std::string get_mecaNumber() const;
    std::string get_name() const;
    std::list<UcTurma> get_turm() const;


    //Student Operator Overloading
    bool operator<(const Student& s) const;

    Student(std::string basicString);
};

#endif //LOADCLASSES_H_STUDENT_H
