#include <iostream>
#include <string>
#include "studentData.hpp"

using namespace std;

void addStudentData(studentData (&students) [], string studentName, int homework, int recitation, int quiz, int exam, int length){
    studentData student;
    student.studentName = studentName;
    student.homework = homework;
    student.recitation = recitation;
    student.quiz = quiz;
    student.exam = exam;
    student.average = ((double)(homework + recitation + quiz + exam))/4.0;
    student.letter = calcLetter(student.average);
    students[length] = student;
}
char calcLetter(double avg){
    if (avg >= 90){
        return 'A';
    } else if (avg >= 80) {
        return 'B';
    } else if (avg >= 70) {
        return 'C';
    } else if (avg >= 60) {
        return 'D';
    } else {
        return 'F';
    } 
}
double avgFromLetter(char letter){
    switch (letter){
        case 'A':
            return 90;
            break;
        case 'B':
            return 80;
            break;
        case 'C':
            return 70;
            break;
        case 'D':
            return 60;
            break;
        default:
            return 0;
            break;
    }
}
void printList(const studentData students[], int length){
    studentData student;
    for(int i = 0; i < length; i++){
        student = students[i];
        cout << student.studentName << " earned " << student.average 
        << " which is a(n): " << student.letter << endl;
    }
}