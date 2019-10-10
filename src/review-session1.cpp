/*
A program written as a review exercise for CMPT128 at SFU.
Ostensibly, it calculates tuition costs when given course ID and contact hours.
Written by Devon Burnham, 2019:10:09S
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Declaring constants given
const double COSTPERHOUR1000 = 25.50;
const double COSTPERHOUR2000 = 33.33;
const double COSTPERHOUR3000 = 36.66;

const int MINCONTACTHOURS = 40;
const int MAXCONTACTHOURS = 200;
const int MINCOURSEID = 1;
const int MAXCOURSEID = 3000;

const int BOUNDARY1000 = 1000;
const int BOUNDARY2000 = 2000;

//verifies legitimacy of given course ID
bool checkCourseId (int cId) 
{
    
    if (cId <= MAXCOURSEID && cId >= MINCOURSEID) return true;

    else 
    {
        cout << "The number of courses is not valid\n";
        cout << "The number of courses should be between 0<N<3001\n";
        cout << "You entered "<< cId << endl;

        return false;
    }
}

//verifies legitimacy of given contact hours
bool checkContactHours(int cHrs)
{
    
    if (cHrs <= MAXCONTACTHOURS && cHrs >= MINCONTACTHOURS) return true;  //if in specified range
    else if (cHrs <= MAXCONTACTHOURS) 
    {
        cout << "Lowest number of contact hours allowed is " << MINCONTACTHOURS << endl;
        cout << "The number of contact hours you entered was " << cHrs << endl;
        return false;
    }

    else 
    {
        cout << "The program should have a maximum of " << MAXCONTACTHOURS << " contact hours\n";
        cout << "The number of contact hours you entered was " << cHrs << endl;
        return false;
    }
}

//outputs final values to the user
void showValues(int courseId, int contactHours, double tuitionRate, double totalTuition)
{
            cout << "The course number is " << courseId << endl;
            cout << "The number of contact hours is " << contactHours << endl;
            cout << "The hourly tuition rate is " << tuitionRate << endl; //if you don't touch it, it outputs correctly
            cout << "The total tuition is " << fixed << setprecision(2) << totalTuition;
}

int main() 
{
    //define and initialize variables
    int courseId = 0;
    int contactHours = 0;
    int tuitionType = 1;
    double totalTuition = 0;
    double tuitionRate = 0.0;
    
    cout << "Enter the course number ";
    cin >> courseId;
    
    //if invalid course ID
    if (!checkCourseId(courseId))
    {
        cout << "GOODBYE :)";
        exit(EXIT_FAILURE);
    }

    cout << "Enter the number of contact hours\n";
    cin >> contactHours;
    
    //if invalid contact hour number
    if(!checkContactHours(contactHours))
    {
        cout << "GOODBYE :)";
        exit(EXIT_FAILURE);
    }

    //default tuitionType = 1.
    if (courseId < BOUNDARY1000) tuitionType = 0;
    else if (courseId > BOUNDARY2000) tuitionType = 2;

    //switch to assign tuition rates and total tuitions
    switch(tuitionType)
    {
        case 0:  totalTuition = COSTPERHOUR1000 * contactHours; tuitionRate = COSTPERHOUR1000; break;
        case 1:  totalTuition = COSTPERHOUR2000 * contactHours; tuitionRate = COSTPERHOUR2000; break;
        case 2:  totalTuition = COSTPERHOUR3000 * contactHours; tuitionRate = COSTPERHOUR3000; break;
        default: cerr << "error"; exit(EXIT_FAILURE);
    }

    showValues(courseId, contactHours, tuitionRate, totalTuition);
    return 0;

}
