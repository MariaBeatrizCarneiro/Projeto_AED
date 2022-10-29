void SchedulePlacment(vector<string>& weekday, const ClassSchedule& schedule)
{
    size_t initial_pos = ((schedule.get_startHour() - 8) / 0.5) * 2;
    size_t last_pos = (((schedule.get_startHour() + schedule.get_duration()) - 8) / 0.5) * 2;
    size_t middle = (initial_pos + (last_pos - initial_pos) / 2);
    weekday[initial_pos] = "--------------";
    string aux = schedule.get_ucTurma().get_ucCode() + '(' + schedule.get_type() + ')';
    weekday[middle] = string(" ", 14 - aux.length() - (14 - aux.length()) / 2) + aux + string(" ", (14 - aux.length()) / 2);
    weekday[last_pos] = "--------------";

}

void StudentSchedule(Manager m)
{
    string meca;
    cout << "Example: 202030247, 202022512, 202050902, 202023362 ..." << endl;
    cout << "Introduce the MecaNumber of the student: ";
    cin >> meca; cout << endl;

    bool error = false;
    if (meca.length() != 9 || !(regex_search(meca, regex("2[0-9]{8}")))) {error = true; cout << "INVALID MECANUMBER!" << endl;}
    if (error) return;

    //Finding the student in LogN time using predicate in a lambda function
    set<Student> students = m.get_students();

    auto it = find_if(students.begin(), students.end(), [&meca](const Student& s) -> bool { return s.get_mecaNumber() == meca;});
    list<UcTurma> turmas = it->get_turm();

    if (turmas.size() == 0){
        cout << "Could't find any student for that specific input. Please introduce the data as exemplified!" << endl;
        return;
    }

    vector<string> monday(56, "              ");
    vector<string> tuesday(56, "              ");
    vector<string> wednesday(56, "              ");
    vector<string> thursday(56, "              ");
    vector<string> friday(56, "              ");

    //For each
    for (const ClassSchedule& s: m.get_schedule())
    {
        for (const UcTurma& t: turmas) {
            if (s.get_ucTurma() == t)
            {
                if (s.get_weekday() == "Monday") {SchedulePlacment(monday, s);}
                else if (s.get_weekday() == "Tuesday") {SchedulePlacment(tuesday, s);}
                else if (s.get_weekday() == "Wednesday") {SchedulePlacment(wednesday, s);}
                else if (s.get_weekday() == "Thursday") {SchedulePlacment(thursday, s);}
                else if (s.get_weekday() == "Friday") {SchedulePlacment(friday, s);}
            }
        }
    }

    cout << "    Hours     |    Monday    |    Tuesday   |   Wednesday  |   Thursday   |    Friday    | " << endl;
    cout << "--------------|--------------|--------------|--------------|--------------|--------------|" << endl;
    cout << "08:00 - 08:30 |" << monday.at(1) << '|' << tuesday.at(1) << '|' << wednesday.at(1) << '|' << thursday.at(1) << '|' << friday.at(1) << '|' << endl;
    cout << "--------------|" << monday.at(2) << '|' << tuesday.at(2) << '|' << wednesday.at(2) << '|' << thursday.at(2) << '|' << friday.at(2) << '|' << endl;
    cout << "08:30 - 09:00 |" << monday.at(3) << '|' << tuesday.at(3) << '|' << wednesday.at(3) << '|' << thursday.at(3) << '|' << friday.at(3) << '|' << endl;
    cout << "--------------|" << monday.at(4) << '|' << tuesday.at(4) << '|' << wednesday.at(4) << '|' << thursday.at(4) << '|' << friday.at(4) << '|' << endl;
    cout << "09:00 - 09:30 |" << monday.at(5) << '|' << tuesday.at(5) << '|' << wednesday.at(5) << '|' << thursday.at(5) << '|' << friday.at(5) << '|' << endl;
    cout << "--------------|" << monday.at(6) << '|' << tuesday.at(6) << '|' << wednesday.at(6) << '|' << thursday.at(6) << '|' << friday.at(6) << '|' << endl;
    cout << "09:30 - 10:00 |" << monday.at(7) << '|' << tuesday.at(7) << '|' << wednesday.at(7) << '|' << thursday.at(7) << '|' << friday.at(7) << '|' << endl;
    cout << "--------------|" << monday.at(8) << '|' << tuesday.at(8) << '|' << wednesday.at(8) << '|' << thursday.at(8) << '|' << friday.at(8) << '|' << endl;
    cout << "10:00 - 10:30 |" << monday.at(9) << '|' << tuesday.at(9) << '|' << wednesday.at(9) << '|' << thursday.at(9) << '|' << friday.at(9) << '|' << endl;
    cout << "--------------|" << monday.at(10) << '|' << tuesday.at(10) << '|' << wednesday.at(10) << '|' << thursday.at(10) << '|' << friday.at(10) << '|' << endl;
    cout << "10:30 - 11:00 |" << monday.at(11) << '|' << tuesday.at(11) << '|' << wednesday.at(11) << '|' << thursday.at(11) << '|' << friday.at(11) << '|' << endl;
    cout << "--------------|" << monday.at(12) << '|' << tuesday.at(12) << '|' << wednesday.at(12) << '|' << thursday.at(12) << '|' << friday.at(12) << '|' << endl;
    cout << "11:00 - 11:30 |" << monday.at(13) << '|' << tuesday.at(13) << '|' << wednesday.at(13) << '|' << thursday.at(13) << '|' << friday.at(13) << '|' << endl;
    cout << "--------------|" << monday.at(14) << '|' << tuesday.at(14) << '|' << wednesday.at(14) << '|' << thursday.at(14) << '|' << friday.at(14) << '|' << endl;
    cout << "11:30 - 12:00 |" << monday.at(15) << '|' << tuesday.at(15) << '|' << wednesday.at(15) << '|' << thursday.at(15) << '|' << friday.at(15) << '|' << endl;
    cout << "--------------|" << monday.at(16) << '|' << tuesday.at(16) << '|' << wednesday.at(16) << '|' << thursday.at(16) << '|' << friday.at(16) << '|' << endl;
    cout << "12:00 - 12:30 |" << monday.at(17) << '|' << tuesday.at(17) << '|' << wednesday.at(17) << '|' << thursday.at(17) << '|' << friday.at(17) << '|' << endl;
    cout << "--------------|" << monday.at(18) << '|' << tuesday.at(18) << '|' << wednesday.at(18) << '|' << thursday.at(18) << '|' << friday.at(18) << '|' << endl;
    cout << "12:30 - 13:00 |" << monday.at(19) << '|' << tuesday.at(19) << '|' << wednesday.at(19) << '|' << thursday.at(19) << '|' << friday.at(19) << '|' << endl;
    cout << "--------------|" << monday.at(20) << '|' << tuesday.at(20) << '|' << wednesday.at(20) << '|' << thursday.at(20) << '|' << friday.at(20) << '|' << endl;
    cout << "13:00 - 13:30 |" << monday.at(21) << '|' << tuesday.at(21) << '|' << wednesday.at(21) << '|' << thursday.at(21) << '|' << friday.at(21) << '|' << endl;
    cout << "--------------|" << monday.at(22) << '|' << tuesday.at(22) << '|' << wednesday.at(22) << '|' << thursday.at(22) << '|' << friday.at(22) << '|' << endl;
    cout << "13:30 - 14:00 |" << monday.at(23) << '|' << tuesday.at(23) << '|' << wednesday.at(23) << '|' << thursday.at(23) << '|' << friday.at(23) << '|' << endl;
    cout << "--------------|" << monday.at(24) << '|' << tuesday.at(24) << '|' << wednesday.at(24) << '|' << thursday.at(24) << '|' << friday.at(24) << '|' << endl;
    cout << "14:00 - 14:30 |" << monday.at(25) << '|' << tuesday.at(25) << '|' << wednesday.at(25) << '|' << thursday.at(25) << '|' << friday.at(25) << '|' << endl;
    cout << "--------------|" << monday.at(26) << '|' << tuesday.at(26) << '|' << wednesday.at(26) << '|' << thursday.at(26) << '|' << friday.at(26) << '|' << endl;
    cout << "14:30 - 15:00 |" << monday.at(27) << '|' << tuesday.at(27) << '|' << wednesday.at(27) << '|' << thursday.at(27) << '|' << friday.at(27) << '|' << endl;
    cout << "--------------|" << monday.at(28) << '|' << tuesday.at(28) << '|' << wednesday.at(28) << '|' << thursday.at(28) << '|' << friday.at(28) << '|' << endl;
    cout << "15:00 - 15:30 |" << monday.at(29) << '|' << tuesday.at(29) << '|' << wednesday.at(29) << '|' << thursday.at(29) << '|' << friday.at(29) << '|' << endl;
    cout << "--------------|" << monday.at(30) << '|' << tuesday.at(30) << '|' << wednesday.at(30) << '|' << thursday.at(30) << '|' << friday.at(30) << '|' << endl;
    cout << "15:30 - 16:00 |" << monday.at(31) << '|' << tuesday.at(31) << '|' << wednesday.at(31) << '|' << thursday.at(31) << '|' << friday.at(31) << '|' << endl;
    cout << "--------------|" << monday.at(32) << '|' << tuesday.at(32) << '|' << wednesday.at(32) << '|' << thursday.at(32) << '|' << friday.at(32) << '|' << endl;
    cout << "16:00 - 16:30 |" << monday.at(33) << '|' << tuesday.at(33) << '|' << wednesday.at(33) << '|' << thursday.at(33) << '|' << friday.at(33) << '|' << endl;
    cout << "--------------|" << monday.at(34) << '|' << tuesday.at(34) << '|' << wednesday.at(34) << '|' << thursday.at(34) << '|' << friday.at(34) << '|' << endl;
    cout << "16:30 - 17:00 |" << monday.at(35) << '|' << tuesday.at(35) << '|' << wednesday.at(35) << '|' << thursday.at(35) << '|' << friday.at(35) << '|' << endl;
    cout << "--------------|" << monday.at(36) << '|' << tuesday.at(36) << '|' << wednesday.at(36) << '|' << thursday.at(36) << '|' << friday.at(36) << '|' << endl;
    cout << "17:00 - 17:30 |" << monday.at(37) << '|' << tuesday.at(37) << '|' << wednesday.at(37) << '|' << thursday.at(37) << '|' << friday.at(37) << '|' << endl;
    cout << "--------------|" << monday.at(38) << '|' << tuesday.at(38) << '|' << wednesday.at(38) << '|' << thursday.at(38) << '|' << friday.at(38) << '|' << endl;
    cout << "17:30 - 18:00 |" << monday.at(39) << '|' << tuesday.at(39) << '|' << wednesday.at(39) << '|' << thursday.at(39) << '|' << friday.at(39) << '|' << endl;
    cout << "--------------|" << monday.at(40) << '|' << tuesday.at(40) << '|' << wednesday.at(40) << '|' << thursday.at(40) << '|' << friday.at(40) << '|' << endl;
    cout << "18:00 - 18:30 |" << monday.at(41) << '|' << tuesday.at(41) << '|' << wednesday.at(41) << '|' << thursday.at(41) << '|' << friday.at(41) << '|' << endl;
    cout << "--------------|" << monday.at(42) << '|' << tuesday.at(42) << '|' << wednesday.at(42) << '|' << thursday.at(42) << '|' << friday.at(42) << '|' << endl;
    cout << "18:30 - 19:00 |" << monday.at(43) << '|' << tuesday.at(43) << '|' << wednesday.at(43) << '|' << thursday.at(43) << '|' << friday.at(43) << '|' << endl;
    cout << "--------------|" << monday.at(44) << '|' << tuesday.at(44) << '|' << wednesday.at(44) << '|' << thursday.at(44) << '|' << friday.at(44) << '|' << endl;
    cout << "19:00 - 19:30 |" << monday.at(45) << '|' << tuesday.at(45) << '|' << wednesday.at(45) << '|' << thursday.at(45) << '|' << friday.at(45) << '|' << endl;
    cout << "--------------|" << monday.at(46) << '|' << tuesday.at(46) << '|' << wednesday.at(46) << '|' << thursday.at(46) << '|' << friday.at(46) << '|' << endl;
    cout << "19:30 - 20:00 |" << monday.at(47) << '|' << tuesday.at(47) << '|' << wednesday.at(47) << '|' << thursday.at(47) << '|' << friday.at(47) << '|' << endl;
    cout << "--------------|" << monday.at(48) << '|' << tuesday.at(48) << '|' << wednesday.at(48) << '|' << thursday.at(48) << '|' << friday.at(48) << '|' << endl;
    cout << "20:00 - 20:30 |" << monday.at(49) << '|' << tuesday.at(49) << '|' << wednesday.at(49) << '|' << thursday.at(49) << '|' << friday.at(49) << '|' << endl;
    cout << "--------------|" << monday.at(50) << '|' << tuesday.at(50) << '|' << wednesday.at(50) << '|' << thursday.at(50) << '|' << friday.at(50) << '|' << endl;
    cout << "20:30 - 21:00 |" << monday.at(51) << '|' << tuesday.at(51) << '|' << wednesday.at(51) << '|' << thursday.at(51) << '|' << friday.at(51) << '|' << endl;
    cout << "--------------|" << monday.at(52) << '|' << tuesday.at(52) << '|' << wednesday.at(52) << '|' << thursday.at(52) << '|' << friday.at(52) << '|' << endl;
    cout << "21:00 - 21:30 |" << monday.at(53) << '|' << tuesday.at(53) << '|' << wednesday.at(53) << '|' << thursday.at(53) << '|' << friday.at(53) << '|' << endl;
    cout << "--------------|" << monday.at(54) << '|' << tuesday.at(54) << '|' << wednesday.at(54) << '|' << thursday.at(54) << '|' << friday.at(54) << '|' << endl;
    cout << "21:30 - 22:00 |" << monday.at(55) << '|' << tuesday.at(55) << '|' << wednesday.at(55) << '|' << thursday.at(55) << '|' << friday.at(55) << '|' << endl;
    cout << "-----------------------------------------------------------------------------------------|" << endl;
}