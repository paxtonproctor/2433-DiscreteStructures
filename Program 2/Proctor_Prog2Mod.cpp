/************************************************************************
*                                                                       *
* Name: Paxton Proctor                                                  *
*                                                                       *
* Course: CMPS-2433-201 , spring 21, Springfellow                       *
*                                                                       *
* Purpose:  Reinforce the concepts of functions;                        *
*also uses while !eof loop pattern and iomanip.h in C++                 *
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

// function Prototypes
void openFiles(ifstream& infile, ofstream& outfile);
void headings(ifstream& infile, ofstream& outfile, double& x);
void evalFunctions(ifstream& infile, ofstream& outfile, double& x);
void evalInversefun(ifstream& infile, ofstream& outfile, double& x);
void evalFunomp(ifstream& infile, ofstream& outfile, double& x);
void evalFuncompinverse(ifstream& infile, ofstream& outfile, double& x);

//Main
int main() {

	// variable X for infile
	double X;

	// Declare input file
	ifstream infile;
	ofstream outfile;

	// calls the heading and input file
	openFiles(infile, outfile);
	headings(infile, outfile, X);

	// reads to the end of file
	while (!infile.eof()) {
		infile >> X;
		outfile << setw(5) << X;
		// calls functions and inverses of them
		evalFunctions(infile, outfile, X);
		evalInversefun(infile, outfile, X);
		evalFunomp(infile, outfile, X);
		evalFuncompinverse(infile, outfile, X);
		outfile << '\n';
	}

	// Closes infile and outfile
	infile.close();
	outfile.close();
	return 0;
}
/************************************************************************
* Purpose: opens input file and ask user for the file                   *
* Recieves: infile and outfile reference                                *
* Returns: nothing                                                      *
************************************************************************/
void openFiles(ifstream& infile, ofstream& outfile) {
	char infileName[40];
	char outfileName[40];

	// ask user for filename
	cout << "Enter the input file name: ";
	cin >> infileName;
	infile.open(infileName);

	// ask user for outfile name
	cout << "Enter the output file name: ";
	cin >> outfileName;
	outfile.open(outfileName);
}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: infile,outfile, and x reference                             *
* Returns: nothing                                                      *
************************************************************************/
void headings(ifstream& infile, ofstream& outfile, double& x) {
	outfile << fixed << setprecision(2) << "Student: Paxton Proctor \n";
	outfile << "Program 2: Function Compositions\n";
	outfile << "f(x) = x+6  g(x) =  7x  f-1(y) = y-6"
		<< "  g-1(y) = y/7\n\n";
	outfile << setw(3) << "x" << setw(7) << "f(x)" << setw(9) << "g(x)" <<
		setw(9) << "fInv(y)" << setw(11) << "gInv(y)" << setw(10)
		<< "f(g(x))" << setw(11) << "g(f(x))" << setw(12) << "fInv(f(x))" <<
		setw(13) << " gInv(g(x))\n";
	outfile << "-------------------------------------------------" <<
		"--------------------------------------\n";
}
/************************************************************************
* Purpose: Prints function answer of f(x) and g(x)                      *
* Recieves: infile,outfile, and x reference                             *
* Returns: nothing                                                      *
************************************************************************/
void evalFunctions(ifstream& infile, ofstream& outfile, double& x) {
	outfile << setw(8) << x + 6 << setw(8) << 7 * x;
}
/************************************************************************
* Purpose: Prints inverse function answer of f(x) and g(x)              *
* Recieves: infile,outfile, and x reference                             *
* Returns: nothing                                                      *
************************************************************************/
void evalInversefun(ifstream& infile, ofstream& outfile, double& x) {
	outfile << setw(8) << x - 6 << setw(8) << x / 7;
}
/************************************************************************
* Purpose: Prints composition of function answer of f(g(x)) and g(f(x)) *
* Recieves: infile,outfile, and x reference                             *
* Returns: nothing                                                      *
************************************************************************/
void evalFunomp(ifstream& infile, ofstream& outfile, double& x) {
	outfile << setw(9) << (7 * x) + 6
		<< setw(9) << 7 * (x + 6);
}
/************************************************************************
* Purpose: Prints composition of inverse function                       *
* answer of f(f(x)) and g(g(x))                                         *
* Recieves: infile,outfile, and x reference                             *
* Returns: nothing                                                      *
************************************************************************/
void evalFuncompinverse(ifstream& infile, ofstream& outfile, double& x) {
	outfile << setw(10) << (x + 6) - 6
		<< setw(10) << (7 * x) / 7;
}