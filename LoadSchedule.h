#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "UcTurma.h"
#include "Manager.h"

using namespace std;

void loadSchedule(Manager& m)
{
    string FILENAME = "classes.csv";

    ifstream file;
    string file_text;
    std::string::size_type sz;
    file.open(FILENAME);

    vector<ClassSchedule> v;

    //Eliminate first line
    getline(file, file_text);


    while(!file.eof()) {

        getline(file, file_text, ',');
        string classCode = file_text;

        getline(file, file_text, ',');
        string ucCode = file_text;

        getline(file, file_text, ',');
        string weekDay = file_text;

        getline(file, file_text, ',');
        string aux = file_text;
        double startHour = atof(aux.c_str());

        getline(file, file_text, ',');
        aux = file_text;
        double duration = atof(aux.c_str());

        getline(file, file_text);
        string type = file_text;

        if (classCode != "")
        {
            UcTurma u = UcTurma(ucCode, classCode);
            ClassSchedule c = ClassSchedule(u, weekDay, startHour, duration, type);
            v.push_back(c);
        }

    }
    m.set_schedule(v);
    file.close();
}


