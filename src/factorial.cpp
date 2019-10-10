#include<iostream>
#include<stdio.h>
using namespace std;

long int Factorial2(int n){
    if (n==0||n==1) return 1;
    else return n*Factorial2(n-1);
}

long int Factorial(int n){
    if (n==0||n==1) return 1;
    int negative = 1;
    if (n<0) {negative = -1; n=-n;}
    long int m = 1;
    for (int i = 1; i<(n+1); i++){
        m*=i;
    }
    return negative*m;
}

int main(){
    printf("%ld", Factorial(-1));
}
