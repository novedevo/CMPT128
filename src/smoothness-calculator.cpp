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

class Placeholder{
private:
    const int MAXROWS = 9;
    const int MINROWS = 1;
    int nRows = 0;
    int attempts = 0;
    bool ifAppend = false;
public:

    void getInput(){
        if (attempts > 5){
            cout<<"No Valid input\n";
            exit(EXIT_FAILURE);
        }
        attempts++;
        cout << "Enter the number of rows in the pyramid:\n"
             << "the number of rows, n must be 9 >= n >= 1: ";
        cin >> nRows;
        checkForErrors();
    }
    void checkForErrors(){
        if (cin.fail()){
            cerr << "You did not enter an integer\n"
                 << "So you did not enter valid number of rows\n"
                 << "TRY AGAIN\n\n";
            reloadCin();
            getInput();
        }
        else if (!(nRows >= MINROWS && nRows <= MAXROWS)){
            cerr<<"The value of the number of rows in the pyramid\n"
                <<"that you entered is out of range.  TRY AGAIN\n\n";
            
            getInput();
        }
        
    }
    void reloadCin(){
        cin.clear();
        cin.sync();
        cin.ignore();
    }
    
    void main(){
        ifAppend = false;
        getInput();
        PrintPattern(nRows, ifAppend);
        nRows -= 2;
        ifAppend = true;
        if(nRows > 1) PrintPattern(nRows, ifAppend);

    }

    void PrintPattern(int rowsOfPattern, bool ifApp){
        ofstream outFile;

        if (ifApp){
            outFile.open("myfile.txt", iostream::app);
        }else{
            outFile.open("myfile.txt");
        }
        if(outFile.fail()){
            cerr << "\nIn function PrintPattern\n";
            cerr << "Could not open output file\n\n";
            exit(EXIT_FAILURE);
        }
        outFile<<right;
        for (int i = 0; i<rowsOfPattern; i++){
            ////cout<<rowsOfPattern;
            int counter1 = 0;
            int counter2 = 1;
            for(int j = 0; j<5+2*i; j++){
                counter2++;
                counter1 += counter2;
                outFile<<setw(5)<<counter1;
            }
            outFile<<endl;
        }
    }
    
};

int section1(){
    cout << fixed << setprecision(3);   //formats correctly for constraints

    SensorDataFile inFile;     //instantiates a new object of type MyInputFileType

    inFile.getInputAndOpen();
    inFile.checkForErrors();
    inFile.getMeasurements();
    inFile.calculate();
    inFile.printValues();

    return 0;
}

int main(){
    ////section1();
    Placeholder po;
    po.main();
    return 0;
}
