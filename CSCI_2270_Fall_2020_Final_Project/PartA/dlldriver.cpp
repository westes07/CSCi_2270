#include "dll.hpp"
#include "../timer.hpp"
#include <string>
#include <fstream>
#include <sstream>

int main(){
    int testData[10000];
    float insert[100], search[100];

    ifstream in;
    in.open("dataSetA.csv");
    
    string line, num;
    getline(in, line);
    std::stringstream ss(line);

    DoubleLL list;

    for (int i = 0; i < 10000; i++){
        getline(ss, num, ',');
        testData[i] = stoi(num);
    }
    in.close();

    for (int i = 0; i < 100; i++){
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < 100; j++){
            list.insert(testData[(i*100)+j]);
        }
        auto stop = chrono::high_resolution_clock::now();
        insert[i] = get_duration<std::chrono::microseconds>(start, stop)/100;
        start = chrono::high_resolution_clock::now();
        for (int k = 0; k < 100; k++){
            list.search((rand() % (99 + ((i+1)*100) - 1)));
        }
        stop = chrono::high_resolution_clock::now();
        search[i] = get_duration<std::chrono::microseconds>(start, stop)/100;
    }

    ofstream out;
    out.open("insert_search_performance_DLL.csv");
    out << "Insert,Search" << endl;

    for (int i = 0; i < 100; i++){
        out << insert[i] << "," << search[i] << endl;
    }
    out.close();
}