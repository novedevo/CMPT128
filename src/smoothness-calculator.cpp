#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//* adds custom member methods, constants, and variables, inherits from ifstream
class SensorDataFile : public ifstream 
{
private:
    const short int MINHEIGHT = -100;   //minimum & maximum y-values that are acceptable
    const short int MAXHEIGHT = 300;
    int lineNumber = 1;
    int numMeasured = 0;    //number of values that have been recorded from the file
    double newHeight = 0.0;
    int numOfMeasurements = 0;  //stores user-defined number of times data was measured
    double sum1 = 0.0;  //accumulates y-values
    double sum2 = 0.0;  //accumulates squared y-values
    double mean = 0.0;
    double rms = 0.0;
    double maxy = MINHEIGHT;    //maximum y-value that was read
    double miny = MAXHEIGHT;    //minumum y-value that was read
    double maxRough = 0.0;

public:
    char inputName[80] = {'\0'};    //strings to store input filename
    
    void getInputAndOpen(void){
        cout << "Enter the input filename:\n";
        cin >> inputName;
        open(inputName);
    }

    int getMeasurements(void){
        while (!eof() && (*this >> newHeight)){ //while file continues and data can correctly be read into a float
            if (lineNumber > numOfMeasurements) {break;} //exit loop if we have measured enough data
            
            lineNumber++;
            
            if (newHeight > MINHEIGHT && newHeight < MAXHEIGHT){    //if within bounds
                cout << newHeight << endl;
                
                sum1 += newHeight;
                sum2 += newHeight * newHeight;    //accumulates the sum of (y-value)^2, for later use
                                                //because we couldn't use arrays
                
                if (newHeight >= maxy) maxy = newHeight;
                if (newHeight <= miny) miny = newHeight;
                
                numMeasured++;
            }
            else cerr << "ERROR: Surface is too rough. Measurement on line " << lineNumber << " will not be used"<<endl;
        }


        if (eof() && lineNumber <= numOfMeasurements){  //if the file ends before it should
            cerr << "ERROR: Insufficient Data, data ends at line " << lineNumber <<endl;
            numOfMeasurements = lineNumber-1;
            return 1;
        }else if (lineNumber > numOfMeasurements){  //if we have measured the correct number of values
            return 0;
        
        }else if (!eof()){  //if it isn't the end of the file, we haven't measured enough, and it couldn't be read correctly
            cerr << "ERROR: Incorrect data in input data file at line " << lineNumber <<endl;
            numOfMeasurements = lineNumber - 1;
            return 1;
        }
    }
    
    int calculate(){
        
        if (!numMeasured) return 1; //if no values were measured

        mean = sum1 / (numMeasured);
        rms = sqrt(sum2 / (numMeasured - 1));   //formulas defined by instructor
        maxRough = maxy - miny;
        
        return 0;
    }

    int printValues(){
        cout << "\n\n";
        
        if (!numMeasured) cout << "\n\nNo data in range.\n";
        
        cout << "The mean smoothness is " << mean << endl;
        cout << "The root mean square smoothness is " << mean << endl;
        cout << "The maximum roughness is " << maxRough << endl;
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

        if (!(numOfMeasurements>0)){
            cerr<<"ERROR: File indicates illegal number (<=0) of smoothness data";
            exit(EXIT_FAILURE);
        }
    }
};

int main(){
    cout << fixed << setprecision(3);   //formats correctly for constraints

    SensorDataFile inFile;     //instantiates a new object of type MyInputFileType

    inFile.getInputAndOpen();
    inFile.checkForErrors();
    inFile.getMeasurements();
    inFile.calculate();
    inFile.printValues();

    return 0;
}
