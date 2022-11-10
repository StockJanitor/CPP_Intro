#include "OfferedCourse.h"

// TODO: Define mutator functions -
//      SetInstructorName(), SetTerm(), SetClassTime()
void OfferedCourse::SetInstructorName(string a)
{
    instructorName = a;
}
void OfferedCourse::SetTerm(string a)
{
    term = a;

}

void OfferedCourse::SetClassTime(string a)
{
    classTime = a;
}

// TODO: Define accessor functions -
//      GetInstructorName(), GetTerm(), GetClassTime()

string OfferedCourse::GetInstructorName()
{
    return instructorName;
}
string OfferedCourse::GetTerm()
{
    return term;
}
string OfferedCourse::GetClassTime()
{
    return classTime;
}
