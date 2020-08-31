#include <iostream>
#include <fstream>

using namespace std;

int addToArrayAsc(float (&sortedArr) [100], int elements, float newValue){
    int index;
    if (elements == 0){
        sortedArr[0] = newValue;
    } else if (newValue > sortedArr[elements - 1]){
        sortedArr[elements] = newValue;
    } else{
        for (int i = 0; i < elements + 1; i++){
            if (newValue < sortedArr[i]){
                index = i;
                break;
            }
            
        }
        for (int i = elements + 1; i > index; i--){
            if (i < 100){
                sortedArr[i] = sortedArr[i - 1];
            }
            
        }
        sortedArr[index] = newValue;
    }
    return elements + 1;
}

int main(int argc, char * argv[]){
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