#include <iostream>
#include <iomanip>
using namespace std;
#include<stdio.h>

int nibbler(unsigned long int a, unsigned long int b){
    unsigned long int c = 0;
    unsigned long int d = 0;
    
    for(unsigned long int i = 0; i<16; i++){
        c=c^((((unsigned long int)0xF)<<(4*(15-i))&a))>>4*(15-i);
        d=d^((((unsigned long int)0xF)<<(4*(15-i))&b))>>4*(15-i);
    }
    return (d|(c<<4));
}

int main(){
    printf( "%d", nibbler( 897345879634, 789441719 ));
}