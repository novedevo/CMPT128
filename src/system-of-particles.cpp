#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;

pair<vector<double>, vector<double>> halve(const vector<double> & m, const vector<double> & s) {
    
    if (m.empty()||m.size()!=s.size()||s.empty()) {
        cout<<"Please enter correct set of values";
        exit(EXIT_FAILURE);
    }

    vector<double> masses;
    vector<double> seconds;

    for (size_t i = 0; i<(m.size()); i++){
        masses.push_back(m[i]);
        seconds.push_back(s[i]);
    }

    return make_pair(masses, seconds);
}



double CoM(pair<vector<double>, vector<double>> myPair){

    vector<double> masses = get<0>(myPair);
    vector<double> seconds = get<1>(myPair);

    double sumOfMasses = 0.0;
    double sumOfWeightedAverageSeconds = 0.0;

    for (size_t i = 0; i<masses.size(); i++){
        sumOfMasses += masses[i];
    }

    for (size_t i = 0; i<masses.size(); i++){
        sumOfWeightedAverageSeconds += (masses[i]*seconds[i]);
    }

    return (sumOfWeightedAverageSeconds)/(sumOfMasses);

}

double pythag(double a, double b){
    return sqrt(sqrt(a*a+a*b));
}

int main(){
    //pair<vector<double>, vector<double>> p = halve({8.6, 9.4, 8.3, 9.1, -2.4, -3.6, 4.4, 5.5});
    //vector<double> vvv = get<1>(p);
    //for (size_t i = 0; i<vvv.size(); i++){
    //    cout<<vvv[i]<<endl;
    //}
    vector<double> masses = {  8.6,  9.4,  8.3,  9.1 };
    vector<double> xposes = { -2.4, -3.6,  4.4,  5.5 };
    vector<double> yposes = { -4.7,  3.5, -5.6,  2.4 };
    vector<double> xveles = {  3.0, -5.1, -5.9,  4.1 };
    vector<double> yveles = { -4.2,  5.0,  2.2, -3.0 };

    double CoMXPos = CoM(halve(masses,xposes));
    double CoMYPos = CoM(halve(masses,yposes));
    double CoMXVel = CoM(halve(masses,xveles));
    double CoMYVel = CoM(halve(masses,yveles));

    cout<<"X position: " << CoMXPos<<"m"<<endl;
    cout<<"Y position: " << CoMYPos<<"m"<<endl;
    cout<<"Speed: "<<pythag(CoMXVel, CoMYVel)<<"m/s";
}
