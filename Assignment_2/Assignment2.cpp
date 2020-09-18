#include <fstream>
#include <iostream>
#include <sstream>
#include "wordCount.hpp"

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 4){
        std::cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return -1;
    }

    int start = stoi(argv[1]);
    string txtfile = argv[2];
    const char * igfile = argv[3];

    string ignoreWords[50];
    getIgnoreWords(igfile, ignoreWords);
    ifstream in;
    in.open(txtfile);
    if(!in){
        std::cout << "Failed to open " << txtfile << endl;
    }
    string line;
    int uniqueCount = 0;
    int doubleCount = 0;
    int totalCount = 0;
    wordRecord *words = new wordRecord[100];
    int capacity = 100;
    bool unique;
    string word;
    while (getline(in, line)){
        stringstream s(line);
        while (getline(s, word, ' ')){
            unique = true;
            if (uniqueCount == capacity){
                int newCapacity = capacity * 2;
                wordRecord* newArr = new wordRecord[newCapacity];
                for(int i = 0; i < capacity; i++){
                    newArr[i] = words[i];
                }
                words = newArr;
                capacity = newCapacity;
            }
            for(int i = 0; i < uniqueCount; i++){
                if(word == words[i].word){
                    words[i].count += 1;
                    totalCount++;
                    unique = false;
                    break;
                }
            }
            if(unique){
                if(!isIgnoreWord(word, ignoreWords) && word != ""){
                    words[uniqueCount] = {word, 1};
                    totalCount++;
                    uniqueCount++;
                }
            }
        }
    }
    sortArray(words, uniqueCount);
    std::cout << "Array doubled: " << doubleCount << endl;
    std::cout << "Distinct non-common words: " << uniqueCount << endl;
    std::cout << "Total non-common words: " << totalCount << endl;
    std::cout << "Probability of next 10 word from rank " << start << endl;
    std::cout << "---------------------------------------" << endl;
    printTenFromN(words, start, totalCount);
}