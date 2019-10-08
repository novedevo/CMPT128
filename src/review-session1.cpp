#include<iostream>
using namespace std;

const double COSTPERHOUR1000 = 25.50;
const double COSTPERHOUR2000 = 33.33;
const double COSTPERHOUR3000 = 36.66;

const int MINCOURSEID = 1;
const int MAXCOURSEID = 3000;

const int BOUNDARY1000 = 1000;
const int BOUNDARY2000 = 2000;

const int MINCONTACTHOURS = 40;
const int MAXCONTACTHOURS = 200;

void invalidCourse(int courseId){
    cout<<"The number of courses is not valid\n";
    cout<<"The number of courses should be between 0<N<3001\n";
    cout<<"You entered "<<courseId<<endl;
    cout<<"GOODBYE :)";
}

void showValues(int validity, int courseId, int contactHours, double tuitionRate, double totalTuition){
            cout<<"The course number is "<<courseId<<endl;
            cout<<"The number of contact hours is "<<contactHours<<endl;
            cout<<"The hourly tuition rate is "<<tuitionRate<<endl;
            cout<<"The total tuition is "<<totalTuition;
}

int main() {
    int courseId = 0;
    int contactHours = 0;
    cout<<"Enter the course number ";
    cin >> courseId;
    cout<<"Enter the number of contact hours\n";
    cin>>contactHours;

}