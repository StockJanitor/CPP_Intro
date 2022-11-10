#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course
{
    // TODO: Declare private data members - instructorName, term, classTime
private:
    string instructorName;
    string term;
    string classTime;

public:
    // TODO: Declare mutator functions -
    //      SetInstructorName(), SetTerm(), SetClassTime()
    void SetInstructorName(string a);
    void SetTerm(string a);
    void SetClassTime(string a);

    // TODO: Declare accessor functions -
    //      GetInstructorName(), GetTerm(), GetClassTime()
    string GetInstructorName();
    string GetTerm();
    string GetClassTime();
};

#endif