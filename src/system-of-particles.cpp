#include<iostream>
#include<list>
#include<vector>
#include<utility>
using namespace std;

pair<vector<double>, vector<double>> xCoM(const vector<double> & v) {
    
    if (v.empty()||v.size()%2!=0) {
        cout<<"please enter correct set of values";
        exit(EXIT_FAILURE);
    }

    vector<double> masses;
    vector<double> positions;

    for (size_t i = 0; i<v.size(); i++){
        masses.push_back(v[i]);
        positions.push_back(v[i+v.size()/2]);
    }

    return make_pair(masses, positions);
}



int main(){
    pair <vector<double>,vector<double>> p = xCoM({8.6, 9.4, 8.3, 9.1});
    cout<<get<1>(p)[1];
}