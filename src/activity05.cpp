#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

const double E = 2.718281828;

class Row {
private:
    double xVal = 0.0;
    bool negative = false;
    
    double eToTheX (double x){
        return pow(E,x);
    }
    double log10X(double x){
        if (!negative) cout << log10(x);
        else cout <<"undef";
    }
    double rootX(double x){
        if (!negative) return sqrt(x);
        else return sqrt(-x);
    }

public:
    Row(double xVal){this->xVal = xVal;};
    
    void output(){
        if (xVal<0) negative=true;
        
        //terrible but working code below
        cout<<fixed<<setprecision(3)<<setw(12)<<xVal;
        cout<<scientific<<setprecision(2)<<setw(15)<<eToTheX(xVal);
        cout<<fixed<<setprecision(5)<<setw(15);
        log10X(xVal);
        cout<<"        ";
        cout<<setprecision(5)<<left<<rootX(xVal)<<right;
        if(negative)cout<<"i";  //if imaginary
        cout<<endl;
    }

};

class Table {

private:
    vector <Row> vectorOfRows;
    int rowCount = 0;
    double initialX = 0.0;
    double increment = 0.0;

    int promptUserForRows(){
        cout<<"Enter the number of rows in the table to be produced\n";
        cout<<"The number of rows must be between 0 and 35\n";
        cin>>rowCount;
        if (cin.fail() || 0>=rowCount || 35<=rowCount){
            cin.clear();
            cin.ignore();
            cout<<"The number you entered was invalid, TRY AGAIN:\n";
            promptUserForRows();
        }

    }

    int promptUserForInitialX(){
        cout<<"Enter the starting X\n";
        cout<<"The starting X must satisfy |X| < 100\n";
        cin>>initialX;
        if (cin.fail() || abs(initialX)>=100){
            cin.clear();
            cin.ignore();
            cout<<"The number you entered was too large, TRY AGAIN:\n";
            promptUserForInitialX();

        }
        else return 0;
    }

    int promptUserForIncrement(){
        cout <<"Enter the increment in X between successive rows\n";
        cout<<"The increment in X must be positive\n";
        cin>>increment;
        if (cin.fail() || increment<0){
            cin.clear();
            cin.ignore();
            cout << "The number you entered was invalid, TRY AGAIN:\n";
            promptUserForIncrement();
        }
        else return 0;
    }

public:
    int getValues(){
        promptUserForRows();
        promptUserForInitialX();
        promptUserForIncrement();
        return 0;
    }

    void output(void){
        cout<<"\n\n\n        X          exp(X)         log10(X)        sqrt(X)\n";
        for (size_t i=0; i<vectorOfRows.size(); i++){
        vectorOfRows[i].output();
        }
    }

    Table(){
        getValues();
        for (unsigned int i=0; i<rowCount; i++){
            Row newRow(initialX+increment*i);
            vectorOfRows.push_back(newRow);
        }
    }

};

int main(){
    Table myTable;
    myTable.output();
    return 0;
}