#ifndef LOADCLASSES_H_CLASSSCHEDULE_H
#define LOADCLASSES_H_CLASSSCHEDULE_H

#include <string>
#include <list>
#include "UcTurma.h"

class ClassSchedule {
private:
    UcTurma ucTurma_;
    std::string weekDay_, type_;
    double startHour_, duration_;

public:
    //ClassSchedule Constructor
    ClassSchedule(UcTurma ucTurma, std::string weekDay, double startHour, double duration, std::string type);

    //ClassSchedule Setters
    void set_ucTurma(UcTurma ucTurma);
    void set_weekDay(std::string weekDay);
    void set_starHour(double startHour);
    void set_duration(double duration);
    void set_type(std::string type);

    //ClassSchedule Getters
    UcTurma get_ucTurma() const;
    std::string get_weekday() const;
    double get_startHour() const;
    double get_duration() const;
    std::string get_type() const;

    //ClassSchedule Methods
    double get_endHour();
};

#endif //LOADCLASSES_H_CLASSSCHEDULE_H
