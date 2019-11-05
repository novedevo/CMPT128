#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

//* adds custom member methods, constants, and variables
class MyInputFileType : public ifstream {
    private:
        const short int MINHEIGHT = -100;   //* minimum & maximum y-values that are acceptable
        const short int MAXHEIGHT = 300;
        int lineNumber = 1;
        int numMeasured = 0;    //*number of values that have been recorded from the file
        double newHeight = 0.0;
        int numOfMeasurements = 0;  //*stores user-defined number of times data was measured
        double sum1 = 0.0;  //accumulates y-values
        double sum2 = 0.0;  //accumulates squared y-values
        double mean = 0.0;
        double rms = 0.0;
        double maxy = MINHEIGHT;    //maximum y-value that was read
        double miny = MAXHEIGHT;    //minumum y-value that was read
        double maxRough = 0.0;
    
    public:
        char inputName[80] = {'\0'};    //strings to store input filename
        
        void getInput(void){
            cout << "Enter the input filename:\n";
            cin >> inputName;
        }

        int getMeasurements(void){
            while (!eof() && (*this >> newHeight)){ //while file continues and data can correctly be read into a float
                ////cout<<endl<<"line number is "<<lineNumber<<endl;
                if (lineNumber > numOfMeasurements){break;} //exit loop if we have measured enough data
                
                lineNumber++;
                
                if (newHeight > MINHEIGHT && newHeight < MAXHEIGHT){    //if within bounds
                    cout << newHeight << endl;
                    
                    sum1 += newHeight;
                    sum2 += newHeight*newHeight;
                    
                    if (newHeight>=maxy) maxy = newHeight;
                    if (newHeight<=miny) miny = newHeight;
                    
                    numMeasured++;

                }else{
                    cerr << "ERROR: Surface is too rough. Measurement on line " << lineNumber << " will not be used"<<endl;
                }

            }

            if (eof()&&lineNumber<=numOfMeasurements){
                cerr << "ERROR: Insufficient Data, data ends at line " << lineNumber <<endl;
                numOfMeasurements = lineNumber-1;
                return 1;
            }else if (lineNumber > numOfMeasurements){
                return 0;
            
            }else if (!eof()){
                cerr << "ERROR: Incorrect data in input data file at line " << lineNumber <<endl;
                numOfMeasurements = lineNumber-1;
                return 1;
            }
        }
        
        int calculate(){
            
            if (!sum1) return 1;

            mean = sum1/(numMeasured);
            rms = sqrt(sum2/(numMeasured-1));
            maxRough = maxy-miny;
            
            ////cout<<endl<<endl<<numOfMeasurements<<endl<<endl;

            cout<<mean<<endl<<rms<<endl<<maxRough<<endl;
            return 0;
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

int main(){
    cout << fixed << setprecision(3);   //formats correctly for constraints
    
    MyInputFileType inFile;

    inFile.getInput();
    inFile.open(inFile.inputName);
    inFile.checkForErrors();
    inFile.getMeasurements();
    if (inFile.calculate()) cout<<"\n\nNo data in range.\n";
}
