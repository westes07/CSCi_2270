#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "studentData.hpp"

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 5){
        cout << " Incorect number of arguments: " << endl;
        return -1;
    }
    
    string inFilename = argv[1];
    string outFilename = argv[2];
    char lower = argv[3][0];
    char upper = argv[4][0]; 
    
    ifstream input;
    input.open(inFilename);
    if (!input){
        cout << "Failed to open the file." << endl;
    }

    string line;
    string name, homework, recitation, quiz, exam;
    studentData students[10];
    int count = 0;
    while (getline(input, line)){
        stringstream s(line);
        getline(s,name,',');
        getline(s,homework,',');
        getline(s,recitation,',');
        getline(s,quiz,',');
        getline(s,exam,',');
        addStudentData(students, name, stoi(homework), stoi(recitation), stoi(quiz), stoi(exam), count);
        count++;
    }
    printList(students, count);
    input.close();

    ofstream output;
    output.open(outFilename);
    double max = avgFromLetter(upper) + 10;
    double min = avgFromLetter(lower);
    studentData student; 
    for(int i = 0; i < count; i++){
        student = students[i];
        if (student.average >= min && student.average <= max){
            output << student.studentName << "," << student.average << "," << student.letter << endl;
        }
        
    }
    output.close();
    return 0;
}