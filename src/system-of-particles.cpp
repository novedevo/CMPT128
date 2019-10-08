#include<iostream>
#include<list>
#include<vector>
#include<utility>
using namespace std;

pair<vector<double>, vector<double>> xCoM(const vector<double> & v) {
    
    if (v.empty()) {
        cout<<"please enter values";
        exit(EXIT_FAILURE);
    }

    vector<double> masses;
    vector<double> positions;

    for (size_t i = 0; i<v.size(); i+=2){
        masses.push_back(v[i]);
        positions.push_back(v[i+1]);
    }

    return make_pair(masses, positions);
}



int main(){
    pair <vector<double>,vector<double>> p = xCoM({8.6, 2.0, 1.3, 2.5});
    cout<<get<0>(p)[1];
}