#include <iostream>
#include <limits.h>

using namespace std;

int nibbler(unsigned long int a, unsigned long int b)
{
    unsigned long int c = 0;
    unsigned long int d = 0;
    
    c = (a&0xF)^((a&0xF0)>>4)^((a&0xF00)>>8)^((a&0xF000)>>12)^((a&0xF0000)>>16)^((a&0xF00000)>>20)^((a&0xF000000)>>24)^((a&0xF0000000)>>28)^((a&0xF00000000)>>32);
    d = (b&0xF)^((b&0xF0)>>4)^((b&0xF00)>>8)^((b&0xF000)>>12)^((b&0xF0000)>>16)^((b&0xF00000)>>20)^((b&0xF000000)>>24)^((b&0xF0000000)>>28)^((b&0xF00000000)>>32);
    return d|(c<<4);
}

int main(){
    unsigned long int a = 0;
    unsigned long int b = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << nibbler(a, b);
}
