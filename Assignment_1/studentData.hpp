#include <string>

struct studentData{
    std::string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData students[], std::string studentName, int homework, int recitation, int quiz, int exam, int length){}
char calcLetter(double avg){}
void printList(const studentData students[], int length){}