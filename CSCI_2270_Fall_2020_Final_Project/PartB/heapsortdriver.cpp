#include "heapsort.hpp"
#include "../timer.hpp"
#include <string>
#include <fstream>
#include <sstream>

int main(){
    float sort[100];
    int testData[10000];

    ifstream in;
    in.open("dataSetA.csv");

    string line, num;
    getline(in, line);
    std::stringstream ss(line);

    for (int i = 0; i < 10000; i++){
        getline(ss, num, ',');
        testData[i] = stoi(num);
    }

    in.close();

    for (int i = 0; i < 100; i++){
        int n = (i+1)*100;
        int tempArr[n];
        auto start = chrono::high_resolution_clock::now();
        Heap heap(n, tempArr);
        heap.sort();
        auto stop = chrono::high_resolution_clock::now();
        sort[i] = get_duration<std::chrono::microseconds>(start, stop);
    }

    ofstream out;
    out.open("heap_sort_performance.csv");
    out << "Elements,Time" << endl;
    for (int i = 0; i < 100; i++){
        out << (i+1)*100 << "," << sort[i] << endl;
    }
    out.close();
}
    