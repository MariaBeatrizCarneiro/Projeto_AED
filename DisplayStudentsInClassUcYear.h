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

    string uc, year, cn;
    cout << "Example: 1, 2, 3, 4, (...), 15 ..." << endl;
    cout << "Introduce a class number: ";
    cin >> cn; cout << endl;

    cout << "Example: L.EIC001, L.EIC002, L.EIC003, L.EIC004, (...), L.EIC025 ..." << endl;
    cout << "Introduce a UC code: ";
    cin >> uc; cout << endl;

    cout << "Example: 1, 2, 3 (...)" << endl;
    cout << "Introduce year: ";
    cin >> year; cout << endl;

    int count = 0;
    bool error = false;

    //Constrains
    if (cn.length() > 2 || !(regex_search(cn, regex("[0-9]{1,2}")))) {cout << "INVALID CLASS NUMBER!" << endl; error = true;}
    if (year.length() > 1 || !(regex_search(year, regex("[1-6]{1}")))) {cout << "INVALID YEAR!" << endl; error = true;}
    if (uc.length() != 8 || !(regex_search(uc,regex("[A-Z]{1}[.]{1}[A-Z]{3}[0-9]{3}")))) {cout << "INVALID UC!" << endl; error = true;}
    if (error) return;

    for (const Student& s: m.get_students()) {


        for (auto t: s.get_turm()) {

            string classCode = t.get_classCode();
            int class_num = std::stoi(&classCode[5]);

            if ( class_num == std::stoi( cn ) && t.get_ucCode() == uc && t.get_year() == year[0] ) {

                    count++;
                    cout << "Student: " << s.get_mecaNumber() << " - " << s.get_name() << endl;
                    break;

            }
        }
    }

    if (count == 0) {
        cout << "Could't find any studdent with class " << cn << " and uc " << uc << " in year " << year << "." << endl;
    }

};

#endif //MAIN_CPP_DISPLAYSTUDENTS_H
