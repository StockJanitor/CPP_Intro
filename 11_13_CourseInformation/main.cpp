/*
LAB: Course information (derived classes)
Given main(), define a Course base class with functions to set and
get the courseNumber and courseTitle. Also define a derived class
OfferedCourse with functions to set and get instructorName, term,
and classTime.
*/

#include "OfferedCourse.h"

int main()
{
    Course myCourse;
    OfferedCourse myOfferedCourse;

    string courseNumber, courseTitle;
    string oCourseNumber, oCourseTitle, instructorName, term, classTime;

    getline(cin, courseNumber);
    getline(cin, courseTitle);

    getline(cin, oCourseNumber);
    getline(cin, oCourseTitle);
    getline(cin, instructorName);
    getline(cin, term);
    getline(cin, classTime);

    myCourse.SetCourseNumber(courseNumber);
    myCourse.SetCourseTitle(courseTitle);
    myCourse.PrintInfo();

    myOfferedCourse.SetCourseNumber(oCourseNumber);
    myOfferedCourse.SetCourseTitle(oCourseTitle);
    myOfferedCourse.SetInstructorName(instructorName);
    myOfferedCourse.SetTerm(term);
    myOfferedCourse.SetClassTime(classTime);
    myOfferedCourse.PrintInfo();

    cout << "   Instructor Name: " << myOfferedCourse.GetInstructorName() << endl;
    cout << "   Term: " << myOfferedCourse.GetTerm() << endl;
    cout << "   Class Time: " << myOfferedCourse.GetClassTime() << endl;
}
