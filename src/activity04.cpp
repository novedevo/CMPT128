/*

Returns all solutions to a quadratic equation with user-provided coefficients.
Includes contingencies for linear and constant equations.
Written using functional programming conventions.
Created by Devon Burnham for CMPT128 at SFU on October 3rd, 2019

*/

//including many headers
#include    <iostream>	//input/output
#include    <cmath>		//sqrt()
#include    <math.h>	//isnan()
#include    <tuple>		//tuple data structure
#include	<iomanip>	//setprecision()
using namespace std;	//set namespace to be most commonly used

bool error = false;

//function to acquire user input for the three coefficients of the quadratic function
tuple <double, double, double> getInitialValues() {
	double coeffa, coeffb, coeffc;
	cout << "Enter the value of the coefficient of the second order (x squared) term:\n";
	cin >> coeffa;
	if (cin.fail()) { error = true; return make_tuple(0.0, 0.0, 0.0); }
	cout << "Enter the value of the coefficient of the first order term:\n";
	cin >> coeffb;
	if (cin.fail()) { error = true; return make_tuple(0.0, 0.0, 0.0); }
	cout << "Enter the value of the constant term:\n";
	cin >> coeffc;
	if (cin.fail()) { error = true; return make_tuple(0.0, 0.0, 0.0); }
	return make_tuple(coeffa, coeffb, coeffc);	//returns the three user-input coefficients in a tuple of three doubles
}

//simple utility function to cout as many linebreaks as input
void lineBreaks(int j) {
	for (int i = 0; i < j; i++) {
		cout << endl;
	}
}

//shows the user their entered values, with correct formatting and precision
void displayInitialValues(tuple <double, double, double> t) {	//takes a tuple of three coefficients

	double coeffa = get<0>(t);	//coeffa is set to the value of t at index 0
	double coeffb = get<1>(t);	//etc
	double coeffc = get<2>(t);

	cout << "The coefficients of the quadratic equation are:\n";

	cout << fixed << setprecision(3);	//fixed decimal point, three decimal places

	cout << "    Coefficient of the second order term is " << coeffa << "," << endl;
	cout << "    Coefficient of the first order term is " << coeffb << "," << endl;
	cout << "    Coefficient of the constant term is " << coeffc << "," << endl;
}

//main mathematical processing function to solve quadratic equations
tuple <double, double, int> solveQuadratic(tuple <double, double, double> t)	//takes a tuple with three coefficients
{
	double a = get<0>(t);	//see comments for displayInitialValues
	double b = get<1>(t);
	double c = get<2>(t);

	if (a == 0.0 && b == 0.0) {	//if constant function
		if (c == 0.0) {	//if all values are roots
			return make_tuple(0.0, 0.0, 4);	//0.0 and 0.0 are placeholders with no meaning. 4 signifies that every value is a root.
		}
		else return make_tuple(nan(""), nan(""), 5);	//nan("") produces the value nan, and since the first two indicies of the tuple both point to nan, this is evaluated in the same way as
																		//a quadratic equation with no roots. The 5 is simply a signifier with no real purpose in this version of activity04
	}
	else if (a==0.0){	//if linear function
        return make_tuple(((-c)/b),nan(""), 1);	//initial value is the root, second value is a placeholder, third value is a signifier without purpose in thie version
    }

    else{	//if true quadratic
    double ans1 = (-b + sqrt(b*b-4*a*c))  /  (2*a);	//ans1 = first root, or nan
    double ans2 = (-b - sqrt(b*b-4*a*c))  /  (2*a);	//ans2 = second root, or nan

    return make_tuple(ans1, ans2, 0);	//returns tuple with the two answers (or nan(s)) and placeholder

    }
}

//function that determines how many roots the equation has through branching, and returns a tuple with a signifier for that number along with said roots.
tuple <int, double, double> branchAnswers(tuple <double, double, int> quadAnswers){	//takes the roots and a signifier int
    
	//initializing accumulators
	unsigned int i = 0;
    unsigned int j = 0;
    

	if (get<2>(quadAnswers) == 4) {//if all values are real roots
		return make_tuple(4, 0.0, 0.0);//return  signifier and two placeholders
	}

    if(isnan(get<0>(quadAnswers))){	//if the first root is nan, i++
        i++;
    }
    if(isnan(get<1>(quadAnswers))){	//if second root is nan, i++
        j++;
    }
    
    if ((i+j)==2){	//if there are no real roots
        return make_tuple(0,0.0,0.0);//no roots, placeholder, placeholder
    }
    else if (j==1){
        return make_tuple(1, get<0>(quadAnswers),0.0);	//next two if statements bring any real roots into the second index, and signify that there are only one real root
    }
    else if (i==1){
        return make_tuple(1, get<1>(quadAnswers),0.0);
    }
    else if (((i+j)==0)&&(get<0>(quadAnswers) == get<1>(quadAnswers))){    //if there are two real roots       //TODO: change so that this actually works with doubles and floats pls
        return make_tuple(2,get<0>(quadAnswers),get<0>(quadAnswers));	//if the two roots are the same, return them and a signifier
    }
    else if ((i+j)==0){
        return make_tuple(3,get<0>(quadAnswers),get<1>(quadAnswers));	//if the two roots are different, return them individually
    }
    else {
        cout << "Error in or before branchAnswers";	//catch errors
		error = true;
        return make_tuple(999,0.0,0.0);	//return 999, an error-signifying value
    }
}

//show the user how many roots there are, and the values of said roots
void showFinalValues(tuple <int, double, double> t){	//takes a tuple with a signifier and two optional values for the roots
	cout << setprecision(2);
    switch(get<0>(t)){		//self-explanatory switch based on signifier digit
        case 0   : cout << "There are no real roots.";                                                     break;
        case 1   : cout << "There is one real root, root1 = "<<get<1>(t)<<".";                             break;
        case 2   : cout << "There is one double root, root1 = root2 = "<<get<1>(t)<<".";                   break;
        case 3   : cout << "There are two real roots, root1 = "<<get<1>(t)<<", root2 = "<<get<2>(t)<<".";  break;
		case 4   : cout << "All values of x are roots";													   break;
		case 999 : cout << "Error before showFinalValues.";                                                break;
		default  : cout << "Error in or before showFinalValues."; error = true;
    }

}

//manages everything and checks for errors
int trueMain() {
	tuple<double, double, double> initialValues = getInitialValues();
	if (error) { cout << "Input error, please rerun program with real number inputs"; return 1; }
	lineBreaks(2);
	displayInitialValues(initialValues);
	lineBreaks(3);
	if (error) { cout << "Display error, please dbug or check environment"; return 1; }
	showFinalValues(branchAnswers(solveQuadratic(initialValues)));
	if (error) { cout << "Math or Logic error, please debug"; return 1; }
	return 0;
}


int main()
{
	return trueMain();
}
