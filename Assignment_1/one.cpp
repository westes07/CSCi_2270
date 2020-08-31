#include <iostream>
#include <fstream>
#include "sortedArr.hpp"

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 2){
        cout << "Incorrect number of arguemnts: <filename>" << endl;
        return -1;
    }
    
    float numArr[100];
    string filename = argv[1];
    ifstream input;
    input.open(filename);
    if (!input)
    {
        cout << "Failed to open the file." << endl;
    }
    
    string line;
    int count = 1;
    while (getline(input, line)){
        addToArrayAsc(numArr, count - 1, stof(line));
        for(int i = 0; i < count; i++){
            if (i != count - 1){
                cout << numArr[i] << ","; 
            } else{
                cout << numArr[i] << endl;
            }
            
            
        }
        count++;
    }
    input.close();
}