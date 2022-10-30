#include <regex>

void ClassOcupation(Manager m) {

    string uc, year, cn;
    cout << "Example: 1, 2, 3, 4, (...), 15 ..." << endl;
    cout << "Introduce a class number: ";
    cin >> cn; cout << endl;

    cout << "Example: 1, 2, 3 (...)" << endl;
    cout << "Introduce year: ";
    cin >> year; cout << endl;

    cout << "Example: L.EIC001, L.EIC002, L.EIC003, L.EIC004 ..." << endl;
    cout << "Introduce UC: ";
    cin >> uc; cout << endl;

    int count = 0;
    bool error = false;

    //Constrains
    if (cn.length() > 2 || !(regex_search(cn, regex("[0-9]{1,2}")))) {cout << "INVALID CLASS NUMBER!" << endl; error = true;}
    if (year.length() > 1 || !(regex_search(year, regex("[1-6]{1}")))) {cout << "INVALID YEAR!" << endl; error = true;}
    if (uc.length() != 8 || !(regex_search(uc,regex("[A-Z]{1}[.]{1}[A-Z]{3}[0-9]{3}")))) {cout << "INVALID UC!" << endl; error = true;}
    if (error) return;

    for (const Student& s: m.get_students()) {

    //Remove last 2 digits in order to compare it
        string turm = year + uc;
        string uc_last_three_;
        turm.erase(2, 1);

        turm = turm.substr(0, turm.length() - 2);

        uc_last_three_ = uc.substr(uc.length() - 3);
        int uc_last_three = 0;

        uc_last_three = stoi(uc_last_three_);

        for (auto t: s.get_turm()) {
            string t_uc = t.get_ucCode();
            t_uc = t_uc.substr(t_uc.length() - 3);
            int t_three_digits = stoi(t_uc);

            if ((t.get_classCode() == (turm + '0' + cn) || t.get_classCode() == (turm + cn)) && uc == t.get_ucCode()) {
                count++;
                break;
            }
            //Because UC are ordered threre is no need to continue the iteration
            if (uc_last_three < t_three_digits) break;
        }
    }

    if (count != 0) {
        cout << "There are " << count << " students at UC " << uc << ", in class number " << cn << " in the " << year << " year!" << endl;
    }
    else {cout << "Could't find any student for that specific input. Please introduce the data as exemplified!" << endl;}
}

