#include <iostream>

int main(){
    int *ptr1=new int;
    *ptr1=5;
    int *ptr2= new int;
    *ptr2=10;
    ptr1 = ptr2;
    ptr1=NULL;
    ptr2=NULL;
}