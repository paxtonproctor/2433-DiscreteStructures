/************************************************************************
*                                                                       *
* Name: Paxton Proctor                                                  *
*                                                                       *
* Course: CMPS-2433-201 , spring 21, Springfellow                       *
*                                                                       *
* Purpose: Using algoritms of Greatest Common Divisor and Least Common  *
* Divisor to the end of file                                            *
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sstream>


using namespace std;

// function Prototypes
void openFiles(ifstream& infile, ofstream& outfile);
void headings(ofstream& outfile);
int gcd(int list[], int& length, int& Y);
int lcm(int list[], int& length, int& Y);
void MAXGCD(ofstream& outfile, int list[], int& length, int& Y);
void MINLCM(ofstream& outfile, int list[], int& length, int& Y);
int READEOL(ifstream& infile, int list[], int& length);


int main() {
	// Declare input file
	ifstream infile;
	ofstream outfile;

	int list[100];
	int Length;
	// Calling the Header and Openfiles Function
	openFiles(infile, outfile);
	headings(outfile);

	for (int i = 0; i < 10; i++) {
		READEOL(infile, list, Length);
		MAXGCD(outfile, list, Length, y);
		MINLCM(outfile, list, Length, y);
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
* Recieves: outfile,y and x reference                                   *
* Returns: nothing                                                      *
************************************************************************/
void headings(ofstream& outfile) {
	outfile << fixed << setprecision(2) << "Student: Paxton Proctor\n";
	outfile << "Maximum GCD and the Minimum LCM Program\n";
	outfile << "10 test cases\n\n";
	outfile << "maxGCD    " << "minLCM\n";
}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: outfile,y and x reference                                   *
* Returns: nothing                                                      *
************************************************************************/
int READEOL(ifstream& infile, int list[], int &length) {
	//code to get the integers until the end of the line
	string line;
	getline(infile, line);
	if (line == "") getline(infile, line);
	length = 0;
	istringstream is(line);
	while (is >> list[length])
		length++;

	return 1;
}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: outfile,y and x reference                                   *
* Returns: GCD                                                          *
************************************************************************/
int gcd(int list[], int& length, int& Y) {
	// if remainder is = 0; then it will return the greatest common number
	if ((list[length] % Y) == 0)
		return length;
	// else it will use the modulo to get the remainder between the two numbers
	else {
		int R = list[length] % Y;
		return gcd(Y, R);
	}

}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: outfile,y and x reference                                   *
* Returns: nothing                                                      *
************************************************************************/
void MAXGCD(ofstream& outfile, int list[], int& length, int& Y) {
	outfile << gcd(list, Y) << "   ";
}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: outfile,y and x reference                                   *
* Returns: LCM                                                          *
************************************************************************/
int lcm(int list[], int& length, int& Y) {
	// gets the 1st value and then divides it by the 
	//gcd and multiples them by the second value
	return (list[length] / (gcd(list, Y) * Y);
}
/************************************************************************
* Purpose: creates and organizes the heading and prints the format      *
* Recieves: outfile,y and x reference                                   *
* Returns: nothing                                                      *
************************************************************************/
void MINLCM(ofstream& outfile, int list[], int& length, int& Y) {
	outfile << lcm(list, Y) << '\n';
}
