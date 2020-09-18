#include <iostream>
#include <fstream>
#include <iomanip>
#include "wordCount.hpp"

using namespace std;

void swap(wordRecord* xp, wordRecord * yp){
    wordRecord temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void getIgnoreWords(const char * ignoreWordFileName, string *ignoreWords){
    ifstream in;
    in.open(ignoreWordFileName);
    string line;
    int count = 0;
    if (in){
        while (getline(in, line)){
            ignoreWords[count] = line;
            count ++;
        }
    } else {
        cout << "Failed to open " << ignoreWordFileName << endl;
    }
}

bool isIgnoreWord(string word, string ignoreWords[]){
    bool isWord = false;
    for (int i = 0; i < 50; i++){
        if(word == ignoreWords[i]){
            isWord = true;
            break;
        }
    }
    return isWord;   
}

int getTotalNumberNonIgnoreWords (wordRecord distinctWords[], int length){
    int count = 0;
    for(int i=0; i < length; i++){
        count += distinctWords[i].count;
    }
    return count;
}

void sortArray(wordRecord distinctWords[], int length){
    wordRecord temp[length];
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length-i-1; j++){
            if(distinctWords[j].count < distinctWords[j+1].count){
                swap(&distinctWords[j], &distinctWords[j+1]);
                distinctWords[j].word[0];
            }
        }
    }
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){
    int limit;
    if(totalNumWords - N >= 10){
        limit = N + 10;
    }else {
        limit = totalNumWords - N;
    }

    cout << setprecision(5) << fixed;
    for(int i = N; i < limit; i++){
        cout << (float) distinctWords[i].count/totalNumWords << " - " << distinctWords[i].word << endl;
    }
}