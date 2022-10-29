#include "Manager.h"

//Manager Constructor Implementation
Manager::Manager() {students_ = {}; schedule_ = {};}
Manager::Manager(std::set<Student> students, std::vector<ClassSchedule> schedule){students_ = students; schedule_ = schedule;}

//Manager Setters Implementation
void Manager::set_students(std::set<Student> students) {students_ = students;}
void Manager::set_schedule(std::vector<ClassSchedule> schedule) {schedule_ = schedule;}

//Manager Getters Implementation
std::set<Student> Manager::get_students() const {return students_;}
std::vector<ClassSchedule> Manager::get_schedule() const {return schedule_;}

//Manager Methods Implementation
void Manager::add_Student(Student s) {students_.insert(s);}
void Manager::add_schedule(ClassSchedule c) {schedule_.push_back(c);}
int Manager::n_students() {return students_.size();}





