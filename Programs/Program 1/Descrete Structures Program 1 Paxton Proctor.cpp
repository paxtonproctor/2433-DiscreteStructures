/************************************************************************
*                                                                       *
* Name: Paxton Proctor                                                  *
*                                                                       *
* Course: CMPS-2433-201 , spring 21, Springfellow                       *
*                                                                       *
* Purpose: The purpose of this code is to convert the binary codes      *
* into gray codes by using a shift right 1 and exclusive or on k to     *
* get the gray code. Then you will take the given gray code and convert *
* it back to decimal number.                                            *
*                                                                       *
*                                                                       *
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// function Prototypes
int computegrayint(int k, int n);
int computegrayposition(int g);

//Main
int main() {
	// Declare input file
	ifstream infile;
	string infilename;
	string outfilename;

	// asking user for there input file
	cout << "Enter the input file name: ";
	cin >> infilename;
	infile.open(infilename);

	// Declare output file and asking for out file name
	ofstream outfile;
	cout << "Enter the output file name: ";
	cin >> outfilename;
	outfile.open(outfilename);

	// Prints out to outfile
	outfile << fixed << setprecision(2) << "Student: Paxton Proctor \n";
	outfile << "*****************************************\n";

	// Declarations
	char fun;
	int Num, Position, numlines;

	// Reading in numlines
	infile >> numlines;

	//start of for loop and for loop runs till the end of lines infile
	for (int i = 0; i < numlines; i++) {

		// if statement determines what function to use
		// Reads in the letters A or B to determine function 1 or 2
		infile >> fun;
		if (fun == 'A') {

			// if A then Function 1 is called
			// read infile of N(position) and K(Num)
			infile >> Position >> Num;
			outfile << computegrayint(Position, Num) << '\n';
		}
		else if (fun == 'B') {

			// else B then function 2 is called
			// read infile of G(Position)
			infile >> Position;
			outfile << computegrayposition(Position) << '\n';
		}
		else {

			// Lets me know if A or B was not stated
			cout << "Function not given";
		}
	}

	// Closes infile and outfile
	infile.close();
	outfile.close();
	return 0;
}
/************************************************************************
* Purpose: computegrayint takes k and shifts it to the right 1          *
* then xor the new number by the original. lastly, it takes the n of the*
* number to produce the graycode.                                       *
* Recieves: n(number of bits per line) and k(the bits)                  *
* Returns: a int graycode                                               *
************************************************************************/
int computegrayint(int n, int k) {

	// declaration
	int shiftk;

	// if statement determines whether n is between 1 and 8
	// and else statement if not between 1 and 8 will result in null

	if (n >= 1 && n <= 8) {

		// if statement determines how many bits will be used
		if (k >= 0 && k < pow(2, n)) {

			// Creates the gray code
			shiftk = (k^(k >> 1));
			return shiftk;
		}
	}
	else {
		return -1;
	}
}
/********************************************************************************
* Purpose: computegrayposition takes g and turns it into graycode number        *
* then it takes it turns it into a binary number. Lastly, it takes the          *
* binary number and puts it into decimal which will give the graycodes position.*
* Recieves: g(graycodes decimal number)                                         *
* Returns: Position of Graycode decimal number                                  *
********************************************************************************/
int computegrayposition(int g) {

	// declaration
	int i;

	// creation of vector 1
	vector<int> v1;

	// if statement determines if 0 return 0
	// else statement will follow the purpose of 2nd function
	if (g == 0)
	{
		return 0;
	}
	else
	{
		// converting decimal to graycode
		for (i = 0; 0 < g; i++) {
			v1.push_back(g % 2);
			g = g / 2;
		}

		// converting graycode to binary
		// creation of gray vector which will produce our solution
		vector<int> gray;

		// since in vector reverse will fix the order of bits
		reverse(v1.begin(), v1.end());

		// shift right 1 bit
		v1.pop_back();

		// sets starting bit of gray = 1
		gray.push_back(1);

		// reads through vector 1 and does exclusive or with gray index
		for (int i = 0; i < v1.size(); i++)
		{
			gray.push_back(gray[i] ^ v1[i]);
		}

		// since in vector reverse will fix the order of bits
		reverse(gray.begin(), gray.end());

		// declaration
		int sum = 0;

		// converting binary to decimal
		for (i = 0; i < gray.size(); i++) {
			if (gray[i] == 1) {
				sum += pow(2, i);
			}
		}
		return sum;
	}
	
}