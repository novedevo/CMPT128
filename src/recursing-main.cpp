#include<iostream>
using namespace std;
//int i = 0;

int main(int i){
    if (i>6) return 0;
    cout<<i<<" ";
    main(++i);
}
