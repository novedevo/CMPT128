#include <iostream>
using namespace std;

/*char changeCase(char c){
    if (c>64&&c<91){
        return c+32;
    }
    else if (c>97&&c<123){
        return c-32;
    }
}*/

char changeCase(char c){
    return c^32;
}

int main(){
    cout<<changeCase('g');
}

