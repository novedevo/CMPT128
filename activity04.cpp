#include    <iostream>
#include    <cmath>
#include    <math.h>
//#include    <typeinfo>
#include    <tuple>
#include<utility>
//#include<pair>
using namespace std;

pair <double, double> solveQuadratic(double a, double b, double c)
{
    if (a==0.0){
        cout<<"test";
        return make_pair((((-1)*c)/a),(nan("")));
    }
    else{
    double ans1 = ((-1)*b + sqrt(b*b-4*a*c))  /  (2*a);
    double ans2 = ((-1)*b - sqrt(b*b-4*a*c))  /  (2*a);
    cout<<ans1<<endl<<ans2;
    return make_pair(ans1, ans2);

    }
}

tuple <int, double, double> branchAnswers(pair <double, double> quadAnswers){
    unsigned int i = 0;
    unsigned int j = 0;
    
    if(isnan(get<0>(quadAnswers))){
        i++;
    }
    if(isnan(get<1>(quadAnswers))){
        j++;
    }
    
    if ((i+j)==2){
        return tuple<int, double, double>(0,0.0,0.0);
    }
    else if (j==1){
        
        return tuple<int, double, double>(1, get<0>(quadAnswers),0.0);
    }
    else if (i==1){
        return tuple<int, double, double>(1, get<1>(quadAnswers),0.0);
    }
    else if (((i+j)==0)&&(get<0>(quadAnswers) == get<1>(quadAnswers))){           //change so that this actually works with doubles and floats pls
        return tuple<int, double, double>(2,get<0>(quadAnswers),get<0>(quadAnswers));
    }
    else if ((i+j)==0){
        return tuple<int, double, double>(3,get<0>(quadAnswers),get<1>(quadAnswers));
    }
    else {
        cout << "Error in or before branchAnswers";
        return tuple<int, double, double>(999,0.0,0.0);
    }
}

void showFinalValues(tuple <int, double, double> t){
    
    switch(get<0>(t)){
        case 0   : cout << "There are no real roots.";                                                  break;
        case 1   : cout << "There is one real root, root1 = "<<get<1>(t);                               break;
        case 2   : cout << "There is one double root, root1 = root2 = "<<get<1>(t);                     break;
        case 3   : cout << "There are two real roots, root1 = "<<get<1>(t)<<", root2 = "<<get<2>(t);    break;
        case 999 : cout << "Error before showFinalValues";                                              break;
        default  : cout << "Error in or before showFinalValues";
    }

}

int main()
{
    //pair <double, double> quadAnswersPair = solveQuadratic(5.0,9.0,2.0);
    //cout<<get<0>(quadAnswersPair)<<endl<<get<1>(quadAnswersPair)<<endl;
    showFinalValues(branchAnswers(solveQuadratic(0.0,5.0,25.0)));
    
    return 0;
}


