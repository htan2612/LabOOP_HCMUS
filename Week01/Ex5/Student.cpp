#include "Student.h"

Student::Student() : theoryScore(0), practiceScore(0) {}
Student::Student(string id, string name, Date dob, double theory, double practice) : studentID(id), fullName(name), dob(dob), theoryScore(theory), practiceScore(practice) {
}

string Student::getStudentID() const {
    return studentID;
}

string Student::getFullName() const {
    return fullName;
}
Date Student::getDob() const {
    return dob;
}

double Student::getTheoryScore() const {
    return theoryScore;
}

double Student::getPracticeScore() const {
    return practiceScore;
}

void Student::setTheoryScore(double s) {
    if (s >= 0 && s <= 10) theoryScore = s;
    else cout << "Invalid score (0-10)" << endl;
}

void Student::setPracticeScore(double s) {
    if (s >= 0 && s <= 10) practiceScore = s;
    else cout << "Invalid score (0-10)" << endl;
}

void Student::input() {
    cout << "Student ID: ";
    cin >> studentID;
    cin.ignore();
    cout << "Full name: ";
    getline(cin, fullName);
    cout << "Date of birth: " << endl;
    dob.input();
    do {
        cout << "Theory score (0-10): ";
        cin >> theoryScore;
    }
    while (theoryScore < 0 || theoryScore > 10);
    do {
        cout << "Practice score (0-10): ";
        cin >> practiceScore;
    }
    while (practiceScore < 0 || practiceScore > 10);
}

void Student::output() const {
    cout << "ID: " << studentID << endl;
    cout << "Name: " << fullName << endl;
    cout << "DOB: "; dob.output();
    cout << "Theory: " << theoryScore << endl;
    cout << "Practice: " << practiceScore << endl;
    cout << "Average: " << averageScore() << endl;
    cout << "Classify: " << classify() << endl;
}

double Student::averageScore() const {
    return (theoryScore + practiceScore) / 2.0;
}

string Student::classify() const {
    double avg = averageScore();
    if (avg >= 8.0) return "Excellent";
    if (avg >= 6.5) return "Good";
    if (avg >= 5.0) return "Average";
    return "Weak";
}

bool Student::isDobValid() const {
    return dob.isValid();
}