#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

const float PI = 3.14159;
const double FOURTHIRDS = 4.0/3.0;

double radius = 0.0;
double circumference = 0.0;
double volume = 0.0;

int main(){

    cout << "enter the radius of the Sphere: ";
    cin >> radius;
    volume = FOURTHIRDS * PI * pow(radius, 3);

    cout << "The volume of the sphere with radius " << radius << " is " << volume;

    }