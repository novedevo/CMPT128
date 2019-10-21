#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

const double E = 2.718281828;

class Row {
private:
    double xVal = 0.0;
    double eXVal = 0.0;
    double logXVal = 0.0;
    double sqrtXVal = 0.0;
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
    
    //double getXVal(){return xVal;}
    Row(double xVal){this->xVal = xVal;};
    
    void output(/*double xVal, double eXVal, double logXVal, double sqrtXVal*/){
        
        //prepForOutput();
        if (xVal<0) negative=true;
        
        cout<<fixed<<setprecision(3)<<setw(12)<<xVal;
        cout<<scientific<<setprecision(2)<<setw(15)<<eToTheX(xVal);
        cout<<fixed<<setprecision(5)<<setw(15);
        log10X(xVal);
        cout<<"        ";
        cout<<setprecision(5)<<left<<rootX(xVal)<<right;
        if(negative)cout<<"i";
        cout<<endl;
    }

};

class Table{

    private:
        vector <Row> vectorOfRows;
        int rowCount = 0;

    public:

        Table (double xVal, double increment, int rowCount){
            
            this->rowCount = rowCount;

            for (unsigned int i=0; i<rowCount; i++){
                Row newRow(xVal+increment*i);
                vectorOfRows.push_back(newRow);
            }
        }
        void output(void){
            for (size_t i=0; i<vectorOfRows.size(); i++){
            vectorOfRows[i].output();
            }
        }
};

int main(){
    double xVal = 1.0;
    double increment = 0.24;
    int numRows = 4;
    cout<<"        X          exp(X)         log10(X)        sqrt(X)"<<endl;

    Table myTable(xVal, increment, numRows);

    myTable.output();

    /*for (unsigned int i=0; i<numRows; i++){
        Row newRow(xVal+increment*i);
        //Table.push_back(newRow);
        newRow.output();
        //cout<<i<<endl<<"test";
    }*/
}