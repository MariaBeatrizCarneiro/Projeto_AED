#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
struct ucTurma
{
    string mecaNumber;
    string classCode;
};
/*
 * LoadUc() returns a vector of structure ucTurma formed by mecaNumber and classCode
 * taking the data from the file "classes_per_uc.csv"
 */

std::vector<ucTurma> LoadUc()
{
    string FILENAME = "classes_per_uc.csv";
    vector<ucTurma> data;

    ifstream file;
    file.open(FILENAME);

    string txt;
    string file_text;


    int i = 0;
    //flag used so that it does not write the first line
    bool flag_first = false;
    while(!file.eof()) {

        getline(file, file_text, ',');
        string meca = file_text;

        getline(file, file_text);
        string code = file_text;

        if (flag_first) {
            if (meca != "" and code != "") { data.push_back({meca, code}); }
        }
        flag_first = true;
        i++;
    }

    file.close();

    return data;
};

