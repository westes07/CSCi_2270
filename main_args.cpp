#include <iostream>

using namespace std;

int main (int argc, char const *argv[]){
    cout << "Number of arguments: ";
    cout << argc << endl;
    for (int i = 0; i < argc; i++){
        cout << "Argument " << i << ": ";
        cout << argv[i] << endl;
    }
}