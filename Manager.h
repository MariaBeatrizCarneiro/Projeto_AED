#ifndef LOADCLASSES_H_MANAGER_H
#define LOADCLASSES_H_MANAGER_H

#include <set>
#include <vector>
#include <queue>
#include "Student.h"
#include "ClassSchedule.h"

class Manager {
private:
    std::set<Student> students_;
    std::vector<ClassSchedule> schedule_;
    //std::queue<request> requests_;

public:
    //Manager Constructor
    Manager();
    Manager(std::set<Student> students, std::vector<ClassSchedule> schedule);

    //Manager Setters
    void set_students(std::set<Student> students);
    void set_schedule(std::vector<ClassSchedule>);

    //Manager Getters
    std::set<Student> get_students() const;
    std::vector<ClassSchedule> get_schedule() const;

    //Manager Methods
    void add_Student(Student s);
    void add_schedule(ClassSchedule c);
    int n_students();

};

#endif //LOADCLASSES_H_MANAGER_H
