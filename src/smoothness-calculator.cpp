#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//TODO: everything is broken pls help

class MyInputFileType : public ifstream{
    private:

        const short int MINHEIGHT = -100;
        const short int MAXHEIGHT = 300;
        int lineNumber = 1;
        double newHeight = 0.0;
        int numOfMeasurements = 0;
        double sum1 = 0.0;
        double sum2 = 0.0;
        double mean = 0.0;
        double rms = 0.0;
        double maxy = MINHEIGHT;
        double miny = MAXHEIGHT;
        double maxRough = 0.0;
    
    public:
        char inputName[80] = {'\0'};
        void getInput(void){
            cout << "Enter the input filename:\n";
            cin >> inputName;
        }

        void getMeasurements(void){
            while (!eof() && (*this >> newHeight)){
                lineNumber++;
                if (lineNumber > numOfMeasurements){break;}
                if (newHeight > MINHEIGHT && newHeight < MAXHEIGHT){
                    cout << setprecision(3) << newHeight << endl;
                    sum1 += newHeight;
                    cout<<endl<<"Sum1 is "<<sum1<<endl;
                    sum2 += newHeight*newHeight;
                    cout<<"Sum2 is "<<sum2<<endl<<endl;
                    if (newHeight>=maxy) maxy = newHeight;
                    if (newHeight<=miny) miny = newHeight;

                }else{
                    cerr << "ERROR: Surface is too rough. Measurement on line " << lineNumber << " will not be used";
                }

            }

            if (eof()&&lineNumber<(numOfMeasurements+1)){
                cerr << "ERROR: Insufficient Data, data ends at line " << lineNumber <<endl;
                numOfMeasurements = lineNumber-1;
            }else if (!eof()){
                cerr << "ERROR: Incorrect data in input data file at line " << lineNumber <<endl;
                numOfMeasurements = lineNumber-1;
            }
        }
        
        void calculate(){
            mean = sum1/(numOfMeasurements);
            rms = sqrt(sum2/(numOfMeasurements));
            maxRough = maxy-miny;
            
            cout<<endl<<endl<<numOfMeasurements<<endl<<endl;

            cout<<mean<<endl<<rms<<endl<<maxRough<<endl;
        }

        void checkForErrors(void){
            if (fail()){
                cerr << "ERROR: Input file \"" << inputName << "\" could not be opened";
                exit(EXIT_FAILURE);
            }

            if (eof()){
                cerr << "ERROR: input file is empty";
                exit(EXIT_FAILURE);
            }

            if (!(*this >> numOfMeasurements)){
                cerr<<"ERROR: Cannot read the number of height measurements";
                exit(EXIT_FAILURE);
            }
            ////cout<<numOfMeasurements;
            if (!(numOfMeasurements>0)){
                cerr<<"ERROR: File indicates illegal number (<=0) of smoothness data";
                exit(EXIT_FAILURE);
            }
        }
};

class MyOutputFileType : public ofstream{

};

int main(){

    MyInputFileType inFile;
    MyOutputFileType outFile;

    double a = 0;
    double b = 0;
    double c = 0;

    inFile.getInput();
    inFile.open(inFile.inputName);
    inFile.checkForErrors();
    inFile.getMeasurements();
    inFile.calculate();



}
