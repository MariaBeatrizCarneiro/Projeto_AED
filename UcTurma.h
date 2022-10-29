#ifndef LOADCLASSES_H_UCTURMA_H
#define LOADCLASSES_H_UCTURMA_H

#include <string>

class UcTurma{
private:
    std::string ucCode_;
    std::string classCode_;

public:
    //UcTurma Default Constructor
    UcTurma();

    //UcTurma Constructor
    UcTurma(std::string ucCode, std::string ClassCode);

    //UcTurma Setters
    void set_ucCode(std::string ucCode);
    void set_classCode_(std::string classCode);

    //UcTurma Getters
    std::string get_ucCode() const;
    std::string get_classCode() const;

    //UcTurma Methods
    char get_year();

    //Student Operator UcTurma
    bool operator==(const UcTurma& t) const;


};

#endif
