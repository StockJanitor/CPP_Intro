#include "Course.h"

// TODO: Define mutator functions -
//       SetCourseNumber(), SetCourseTitle()
void Course::SetCourseNumber(string a)
{
    courseNumber = a;
}
void Course::SetCourseTitle(string a)
{
    courseTitle = a;
}

// TODO: Define accessor functions -
//       GetCourseNumber(), GetCourseTitle()
string Course::GetCourseNumber()
{
    return courseNumber;
}
string Course::GetCourseTitle()
{
    return courseTitle;
}
// TODO: Define PrintInfo()
void Course::PrintInfo()
{
    cout << "Course Information: " << endl;
    cout << "   Course Number: " << courseNumber << endl;
    cout << "   Course Title: " << courseTitle << endl;
}