#include<stdio.h>
#include<math.h>

//* boundaries of input x
const double lowBound = -1.0;
const double highBound = 1.0;

double getXMin(){
    double xMin = 0.0;
    printf("enter xMin, the smallest x used in the table %7.3lf < x < %8.3lf\n", lowBound, highBound);
    scanf("%lf", &xMin);
    //TODO: check if it's actually within bounds
    return xMin;
}

double getXMax(){
    double xMax = 0.0;
    printf("enter xMax, the largest x used in the table %7.3lf < x < %8.3lf\n", lowBound, highBound);
    scanf("%lf", &xMax);
    //TODO: check if it's actually within bounds
    return xMax;
}

int getRows(){
    int rows = 0;
    printf("Enter the number of rows in the table (an integer)");
    scanf("%d", &rows);
    return rows;
}

double cos3T(double x){     //* approximates value of cos(x) with three terms of a series
    return (1-pow(x, 2)/2+pow(x, 3)/24);
}

double sin3T(double x){     //* same as above but for sin
    return (x-pow(x,3)/6+pow(x,5)/120);
}

int printTable(double min, double x, int r){
    double n=min;
    double increment = ((x-n)/r);
    
    for (int i=0; i<=r; i++){
        
        //* disgusting long printf statement but works
        //* prints all values requested in a table with correct spacing, formatting, & precision
        
        printf("%9.5lf%10.5lf%13.4e%10.5lf%13.4e%10.5lf%13.4e\n", n, sin3T(n), sin(n)-sin3T(n), cos3T(n), cos(n)-cos3T(n), sin3T(2*n), sin3T(2*n)-sin(2*n));
        n+=increment;
    }
}

int main(){

    double xMin = getXMin();
    double xMax = getXMax();
    int rows = getRows();


    //* Kludgy but works
    printf("        X  sin3T(x)      error1   cos3T(x)      error2  sin3T(2x)      error3\n");

    printTable(xMin, xMax, rows-1);

    return 0;
}
