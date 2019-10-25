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

double MultiplyVolSurfSphere(double radius){
    double SA = 4.0*3.14*radius*radius;
    double area = (4.0/3.0)*3.14*radius*radius*radius;
    return SA*area;
}

int SelectSubtract(int num1, int num2, int num3, int num4, int x, int y){
    int sumAll  = num1+num2+num3+num4;
    int prodAll = num1*num2*num3*num4;
    if ((x<1||x>4)&&(y<1||y>4)) return prodAll-sumAll;
    else if (x<1||x>4) return sumAll;
    else if (y<1||y>4) return prodAll;
    
    int countera = 0;
    int counterb = 0;

    switch(x){
        case 1: countera = num1;break;
        case 2: countera = num2;break;
        case 3: countera = num3;break;
        case 4: countera = num4;break;
    }
    switch(y){
        case 1: counterb = num1;break;
        case 2: counterb = num2;break;
        case 3: counterb = num3;break;
        case 4: counterb = num4;break;
    }
    return counterb-countera;

}

int main(){
    printf("%d",    SelectSubtract(11,21,31,41,3,1)    );
}
