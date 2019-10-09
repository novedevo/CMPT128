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

bool checkCourseId(int cId){
    if (cId<=MAXCOURSEID&&cId>=MINCOURSEID){
        return true;
    }
    else {
        cout<<"The number of courses is not valid\n";
        cout<<"The number of courses should be between 0<N<3001\n";
        cout<<"You entered "<<cId<<endl;
        return false;
    }
}

bool checkContactHours(int cHrs){
    if (cHrs<=MAXCONTACTHOURS&&cHrs>=MINCONTACTHOURS) return true;
    else if (cHrs<=MAXCONTACTHOURS){
        cout<<"Lowest number of contact hours allowed is "<<MINCONTACTHOURS<<endl;
        cout<<"The number of contact hours you entered was "<<cHrs<<endl;
        return false;
    }
    else{
        cout<<"The program should have a maximum of "<<MAXCONTACTHOURS<<" contact hours\n";
        cout<<"The number of contact hours you entered was " <<cHrs<<endl;
        return false;
    }
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
    if (!checkCourseId(courseId)){
        cout<<"GOODBYE :)";
        exit(EXIT_FAILURE);
    }

    cout<<"Enter the number of contact hours\n";
    cin>>contactHours;
    if(!checkContactHours(contactHours)){
        cout<<"GOODBYE :)";
        exit(EXIT_FAILURE);
    }

}