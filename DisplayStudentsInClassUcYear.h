//
// Created by Maria Beatriz Monteiro Carneiro on 29/10/2022.
//

#include <regex>
#include <string>
#include <list>
#include "UcTurma.h"

#ifndef MAIN_CPP_DISPLAYSTUDENTS_H
#define MAIN_CPP_DISPLAYSTUDENTS_H

void DisplayStudentsInClassUcYear(Manager m) {

    string uc, year, cn, sortchoice, sortorder, studentnum;
    cout << "Example: 1, 2, 3, 4, (...), 15 ..." << endl;
    cout << "Introduce a class number: ";
    cin >> cn; cout << endl;

    cout << "Example: L.EIC001, L.EIC002, L.EIC003, L.EIC004, (...), L.EIC025 ..." << endl;
    cout << "Introduce a UC code: ";
    cin >> uc; cout << endl;

    cout << "Example: 1, 2, 3 (...)" << endl;
    cout << "Introduce year: ";
    cin >> year; cout << endl;

    cout << "Do you want the students to be display sorted by name or mecanumber? Select 'n' for name or 'm' for mecanumber: ";
    cin >> sortchoice; cout << endl;

    cout << "Do you want the sorting to be ascending or descending? Select 'a' for ascending or 'd' for descending: ";
    cin >> sortorder; cout << endl;

    cout << "Example: 1, 2, 3, (...)" << endl;
    cout << "Introduce the number of the students that you would like to see (select 't' to see the total of students): ";
    cin >> studentnum; cout << endl;

    int count = 0;
    bool error = false;

    long student_num = -1;
    try {
        student_num = std::stol(studentnum);
    }
    catch(...) {};


    //Constrains
    if (cn.length() > 2 || !(regex_search(cn, regex("[0-9]{1,2}")))) {cout << "INVALID CLASS NUMBER!" << endl; error = true;}
    if (year.length() > 1 || !(regex_search(year, regex("[1-6]{1}")))) {cout << "INVALID YEAR!" << endl; error = true;}
    if (uc.length() != 8 || !(regex_search(uc,regex("[A-Z]{1}[.]{1}[A-Z]{3}[0-9]{3}")))) {cout << "INVALID UC!" << endl; error = true;}
    if (sortchoice.length() != 1 || !(regex_search(sortchoice,regex("[m|n]{1}")))) {cout << "INVALID SORT CHOICE!" << endl; error = true;}
    if (sortorder.length() != 1 || !(regex_search(sortorder,regex("[a|d]{1}")))) {cout << "INVALID SORT ORDER!" << endl; error = true;}
    if (studentnum.length() > 3 || !(regex_search(studentnum,regex("[0-9]{0,2}[t]{0,1}")))) {cout << "INVALID STUDENT NUMBER!" << endl; error = true;}
    if (error) return;

    auto cmpna = [](const Student& a, const Student& b) { return a.get_name() < b.get_name(); };
    auto cmpnd = [](const Student& a, const Student& b) { return a.get_name() > b.get_name(); };
    auto cmpma = [](const Student &a, const Student &b) { return a.get_mecaNumber() < b.get_mecaNumber(); };
    auto cmpmd = [](const Student &a, const Student &b) { return a.get_mecaNumber() > b.get_mecaNumber(); };

    std::set<Student, decltype(cmpna)> studentSetNA(cmpna);
    std::set<Student, decltype(cmpnd)> studentSetND(cmpnd);
    std::set<Student, decltype(cmpma)> studentSetMA(cmpma);
    std::set<Student, decltype(cmpmd)> studentSetMD(cmpmd);

    studentSetNA.clear();
    studentSetND.clear();
    studentSetMA.clear();
    studentSetMD.clear();

    for (const Student &s: m.get_students()) {

        for (auto t: s.get_turm()) {

            if (t.get_ucCode() == uc && t.get_year() == year[0]) {

                string classCode = t.get_classCode();
                int class_num = std::stoi(&classCode[5]);

                if (class_num == std::stoi(cn)) {

                    count++;

                    if (sortchoice == "n" ) {
                        if ( sortorder == "a"){
                            studentSetNA.insert(s);
                        }
                        if ( sortorder == "d") {
                            studentSetND.insert(s);
                        }
                    }

                    if (sortchoice == "m" ) {
                        if (sortorder == "a") {
                            studentSetMA.insert(s);
                        }
                        if (sortorder == "d") {
                            studentSetMD.insert(s);
                        }
                    }

                    break;
                }
            }
        }
    }

    int i = 0;
    for (auto studentNA = studentSetNA.begin(); studentNA != studentSetNA.end(); ++studentNA) {
        i++;
        cout << studentNA->get_mecaNumber() <<' ' << studentNA->get_name() << endl;
        if(student_num != -1 && i >= student_num)
            break;
    }

    i = 0;
    for (auto studentND = studentSetND.begin(); studentND != studentSetND.end(); ++studentND) {
        i++;
        cout << studentND->get_mecaNumber() <<' ' << studentND->get_name() << endl;
        if(student_num != -1 && i >= student_num)
            break;
    }

    i = 0;
    for (auto studentMA = studentSetMA.begin(); studentMA != studentSetMA.end(); ++studentMA) {
        i++;
        cout << studentMA->get_mecaNumber() <<' ' << studentMA->get_name() << endl;
        if(student_num != -1 && i >= student_num)
            break;
    }

    i = 0;
    for (auto studentMD = studentSetMD.begin(); studentMD != studentSetMD.end(); ++studentMD) {
        i++;
        cout << studentMD->get_mecaNumber() <<' ' << studentMD->get_name() << endl;
        if(student_num != -1 && i >= student_num)
            break;
    }


    if (count == 0) { cout << "Could't find any studdent with class " << cn << " and uc " << uc << " in year " << year << "." << endl; }

};

#endif //MAIN_CPP_DISPLAYSTUDENTS_H