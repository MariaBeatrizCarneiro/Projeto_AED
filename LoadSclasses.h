#include <fstream>
#include <iostream>
#include "Student.h"
#include "UcTurma.h"
#include "Manager.h"

 using namespace std;

 void loadStudentClasses(Manager& m)
{
    string FILENAME = "students_classes.csv";

    ifstream file;
    string file_text;
    file.open(FILENAME);

    string mecaNumber_ant;
    string studentName_ant;

    list<UcTurma> l;

    //Eliminate first line
    getline(file, file_text);
    bool flag = false;

    while(!file.eof()) {

        getline(file, file_text, ',');
        string mecaNumber = file_text;

        getline(file, file_text, ',');
        string studentName = file_text;

        getline(file, file_text, ',');
        string ucCode = file_text;

        getline(file, file_text);
        string classCode = file_text;



        if (mecaNumber != mecaNumber_ant and flag) {
            Student s = Student(mecaNumber_ant, studentName_ant, l, "Name");
            m.add_Student(s);
            l.clear();
            UcTurma u = UcTurma(ucCode, classCode);
            l.push_back(u);
        }
        else
        {
            UcTurma u = UcTurma(ucCode, classCode);
            l.push_back(u);
        }

        studentName_ant = studentName;
        mecaNumber_ant = mecaNumber;
        flag = true;
        }
    file.close();
}
