#include "sortedArr.hpp"

int addToArrayAsc(float sortedArr[], int elements, float newValue){
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