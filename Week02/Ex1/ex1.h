#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string fullName;
    int id;
    double score1, score2, score3;
    double gpa;
    static int nextID;
    static Student* highestGPAStudent;
    void calculateGPA();
    double validateScore(double score);

public:
    Student();
    Student(string name, double s1, double s2, double s3);
    void SetFullName(string name);
    void SetScores(double s1, double s2, double s3);
    void PrintInfo() const;
    static void GetHighestAverageStudent();
};