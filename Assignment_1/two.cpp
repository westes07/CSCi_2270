#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char * argv[]){
    if (argc != 5){
        cout << " Incorect number of arguments: " << endl;
        return -1;
    }
    
    string inFilename = argv[1];
    string outFilename = argv[2];
    string lower = argv[3];
    string upper = argv[4]; 
    
    ifstream input;
    input.open(inFilename);
    if (!input){
        cout << "Failed to open the file." << endl;
    }
    return 0;
}