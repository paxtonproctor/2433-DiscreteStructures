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
int gcd(int X, int Y);
int FindMaxGCD(int list[], int& length);
int FindMinLCM(int list[], int& length);
void READEOL(ifstream& infile, int list[], int& length);


int main() {
	// Declare input file
	ifstream infile;
	ofstream outfile;

	int list[100];
	int Length = 0;
	// Calling the Header and Openfiles Function
	openFiles(infile, outfile);
	headings(outfile);

	// reads to the end of file
	int numlines = 0;
	infile >> numlines;
	for (int i = 0; i < numlines; i++) {

		// Calling the readeol, findmaxgcd, findminlcm Function
		READEOL(infile, list, Length);
		outfile << setw(5) << FindMaxGCD(list, Length) << setw(10);
		outfile << FindMinLCM(list, Length) << '\n';
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
* Recieves: outfile                                                     *
* Returns: nothing                                                      *
************************************************************************/
void headings(ofstream& outfile) {
	outfile << fixed << setprecision(2) << "Student: Paxton Proctor\n";
	outfile << "Maximum GCD and the Minimum LCM Program\n";
	outfile << "10 test cases\n\n";
	outfile << "maxGCD    " << "minLCM\n";
}
/************************************************************************
* Purpose: reads to the end of line                                     *
* Recieves: infile, list[] and length reference                         *
* Returns: nothing                                                      *
************************************************************************/
void READEOL(ifstream& infile, int list[], int& length) {
	//code to get the integers until the end of the line
	string line;
	getline(infile, line);
	if (line == "") getline(infile, line);
	length = 0;
	istringstream is(line);
	while (is >> list[length])
		length++;
}
/************************************************************************
* Purpose: creates gcd                                                  *
* Recieves: y and x                                                     *
* Returns: GCD                                                          *
************************************************************************/
int gcd(int X, int Y) {
	// if remainder is = 0; then it will return the greatest common number
	if ((X % Y) == 0) {
		return Y;
	}
	// else it will use the modulo to get the remainder between the two numbers
	else {
		return gcd(Y, X % Y);
	}
}
/************************************************************************
* Purpose: finds the max gcd value                                      *
* Recieves: list[] and length reference                                 *
* Returns: max                                                          *
************************************************************************/
int FindMaxGCD(int list[], int& length) {
	int result;
	int max = 0;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			result = gcd(list[i], list[j]);

			if (result > max) {
				max = result;
			}
		}
	}
	return max;
}
/************************************************************************
* Purpose: creates and finds the min lcm value                          *
* Recieves: list[] and length reference                                 *
* Returns: min LCM                                                      *
************************************************************************/
int FindMinLCM(int list[], int& length) {
	int ans = INT_MAX;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {

			int g = gcd(list[i], list[j]);
			int lcm = list[i] / g * list[j];
			ans = min(ans, lcm);
		}
	}
	return ans;
}
