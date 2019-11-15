#include <iostream>
#include<iomanip>
#include <fstream>
//#include <random>

using namespace std;

class ArrayOfRandomInts {
    private:
        int numGenerated[100] = {0};
        int numRandInt = 0;
        int mySeed = 0;
        int maxRatio = 0;
        int minRatio = 0;
        int maxRandInt = 0;
        int minRandInt = 0;
        int numInMean = 0;
        int myMean = 0;
        int numInVar = 0;
        int numToPrint = 0;
        int sum = 0;
        double sum2 = 0;

    public:
        ArrayOfRandomInts(){}
        void RandomFill(int mySeed, int maxRandInt, int minRandInt){
            //this->mySeed = mySeed;
            srand(mySeed);

            //maxRatio = minRandInt+(maxRandInt-minRandInt)/RAND_MAX;
            
            for (size_t i = 0; i<100; i++){
                numGenerated[i] = (std::rand() % maxRandInt) + minRandInt;
                sum+=numGenerated[i];
            }
        }
        double MeanOfArray(){
            myMean = (double)sum/100;
            return myMean;
        }
        double VarOfArray(){
            for(size_t i = 0; i<100; i++){
                sum2+=(numGenerated[i]-myMean)*(numGenerated[i]-myMean);
            }
            return sum2/99;
        }
        void printArray(std::ostream& myStream, int numPerLine, int colWidth){
            int i = 0;
            while(i<100){
                for (int j = 0; j<numPerLine; j++){
                    cout<<setw(colWidth)<<numGenerated[i];
                    i++;
                }
                cout<<endl;
            }
        }
};

int main(){

    ArrayOfRandomInts arrr;
    arrr.RandomFill(23456,7, -4);
    arrr.printArray(cout, 10, 3);
    cout<<arrr.MeanOfArray();
    cout<<endl;
    cout<<arrr.VarOfArray();
}