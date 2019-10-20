#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

class row {

private:
    
    double xVal = 0.0;
    double eXVal = 0.0;
    double logXVal = 0.0;
    double sqrtXVal = 0.0;

    bool irrational = true;

    void prepForOutput(){
        cout<<"        X          exp(X)        log10(X)        sqrt(X)"<<endl;
    }

public:
    
    //double getXVal(){return xVal;}
    row(double xVal){this->xVal = xVal;};
    
    void output(/*double xVal, double eXVal, double logXVal, double sqrtXVal*/){
        
        prepForOutput();
        
        cout<<fixed<<setprecision(3)<<setw(12)<<xVal;
        cout<<scientific<<setprecision(2)<<setw(15)<<eXVal;
        cout<<fixed<<setprecision(5)<<setw(15)<<logXVal;
        cout<<"        ";
        cout<<setprecision(5)<<left<<sqrtXVal;
        if(irrational)cout<<"i";
    }

};

int main(){
    row row1(16.7);
    row1.output();
    //cout<<row1.getXVal();
}