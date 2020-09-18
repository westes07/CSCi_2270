#include <string>

struct wordRecord{
    std::string word;
    int count;
};

wordRecord* doubleCapacity(wordRecord* arrPtr, int& capacity);
void getIgnoreWords(const char * ignoreWordFileName, std::string ignoreWords[]);
bool isIgnoreWord(std::string word, std::string ignoreWords[]);
void sortArray(wordRecord distinctWords[], int length);
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);
void swap(wordRecord *xp, wordRecord *yp);