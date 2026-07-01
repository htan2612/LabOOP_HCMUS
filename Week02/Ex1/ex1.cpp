#include "ex1.h"
#include <cmath>
#include <iomanip>

int Student::nextID = 1363001;
Student* Student::highestGPAStudent = nullptr;

void Student::calculateGPA() {
    double raw_gpa = (score1 + score2 + score3) / 3.0;
    gpa = round(raw_gpa * 100.0) / 100.0; 

    if (highestGPAStudent == nullptr || this->gpa > highestGPAStudent->gpa) {
        highestGPAStudent = this;
    }
}

double Student::validateScore(double score) {
    return abs(score);
}

Student::Student() {
    id = nextID++;
    fullName = "";
    score1 = score2 = score3 = 0.0;
    gpa = 0.0;
}

Student::Student(string name, double s1, double s2, double s3) {
    id = nextID++;
    fullName = name;
    score1 = validateScore(s1);
    score2 = validateScore(s2);
    score3 = validateScore(s3);
    calculateGPA();
}

void Student::SetFullName(string name) {
    fullName = name;
}

void Student::SetScores(double s1, double s2, double s3) {
    score1 = validateScore(s1);
    score2 = validateScore(s2);
    score3 = validateScore(s3);
    calculateGPA();
}

void Student::PrintInfo() const {
    cout << "Student: " << fullName << ", ID: " << id << ", GPA: " << fixed << setprecision(2) << gpa << endl;
}

void Student::GetHighestAverageStudent() {
    if (highestGPAStudent != nullptr) {
        highestGPAStudent->PrintInfo();
    }
    else {
        cout << "No student data available." << endl;
    }
}