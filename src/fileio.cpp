#include <iostream>
#include <fstream>
using namespace std;

int main(){

int x; float y; char z; bool b;

ifstream myInStream;
ofstream myOutStream;

myInStream.open("data.txt");

if (myInStream.fail()){
    cout<<"File open failed.\n";
    exit(1);
}
myInStream>>x;
myInStream.close();
return 0;
}
