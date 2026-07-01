#include "ex1.h"

int main()
{
    Student s1;
    s1.SetFullName("Nguyen Van A");
    s1.SetScores(7, 8, 10);

    Student s2("Tran Thi B", 5, 8, 4.5);
    Student s3("Hoang Thi C", -9.5, 8.5, 4.5);
    Student s4("Le Van D", 7.5, 9, -10);

    s1.PrintInfo();
    s2.PrintInfo();
    s3.PrintInfo();
    s4.PrintInfo();

    cout << "Student with the highest GPA:" << endl;
    Student::GetHighestAverageStudent();

    return 0;
}