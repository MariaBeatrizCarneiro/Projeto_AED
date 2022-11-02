#include "Student.h"

//Student Constructor Implementation
Student::Student() {mecaNumber_ = "default"; name_ = "default"; turm_ = {};}
Student::Student(std::string mecaNumber, std::string name, std::list<UcTurma> turm, std::string order) {mecaNumber_ = mecaNumber; name_ = name; turm_ = turm;}

//Student Setters Implementation
void Student::set_mecaNumber(std::string) {mecaNumber_ = mecaNumber_;}
void Student::set_name(std::string name) {name_ = name;}
void Student::set_turm(std::list<UcTurma> turm) {turm_ = turm;}


//Student Getters Implementation
std::string Student::get_mecaNumber() const {return mecaNumber_;}
std::string Student::get_name() const {return name_;}
std::list<UcTurma> Student::get_turm() const {return turm_;}


//Student Operator Overloading Implementation
bool Student::operator<(const Student& s) const {
    {return mecaNumber_ < s.mecaNumber_;}
}

Student::Student(std::string basicString) {

}

