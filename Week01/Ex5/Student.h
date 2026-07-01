#pragma once
#include <string>
#include "Date.h"
using namespace std;

class Student {
private:
    string studentID;
    string fullName;
    Date dob;
    double theoryScore;
    double practiceScore;
public:
    Student();
    Student(string id, string name, Date dob, double theory, double practice);
    string getStudentID() const;
    string getFullName() const;
    Date getDob() const;
    double getTheoryScore() const;
    double getPracticeScore() const;
    void setTheoryScore(double s);
    void setPracticeScore(double s);
    void input();
    void output() const;
    double averageScore() const;
    string classify() const;
    bool isDobValid() const;
};