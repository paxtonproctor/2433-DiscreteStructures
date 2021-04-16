/************************************************************************
*                                                                       *
* Name: Paxton Proctor                                                  *
*                                                                       *
* Course: CMPS-2433-201 , spring 21, Springfellow                       *
*                                                                       *
* Purpose:                                                              *
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>   //fix, setw
#include <stdlib.h> //srand, rand
#include <chrono>
#include <time.h>    //clock, clock_t
#include <vector>

using namespace std;

const int MAXSIZES = 5;

// function Prototypes
void openFile(ofstream& outfile);
void printPageHeading(ofstream& outfile);
void printColumnHeadings(ofstream& outfile, long n);
void iBinSearch(int* x, long left, long right, int key);
void rBinSearch(int* x, long left, long right, int key);
void iMergeSort(int* x, long left, long right);
void rMergeSort(int* x, long left, long right);
void Merge(int* x, long left, long m, long right);
void genValues(int* x, int* y, long n);

int main()
{
	// declaring outfile
	ofstream outfile;
	
	//Use the high_resolution_ clock to time in nanoseconds
	using Clock = chrono::high_resolution_clock;
	int sizes[MAXSIZES] = { 100, 1000, 10000, 100000, 1000000 };

	//variables for timings
	clock_t start, stop;
	long long iMergeelapsedTime;
	long long rMergeSortelapsedTime;
	long long iBinelapsedTime;
	long long rBinelapsedTime;

	// declaring for array and subarrays
	int* x;
	int* y;
	long Right, Left;

	// call function to open files
	openFile(outfile);

	//Do for different sizes of arrays in increasing order of magnitude
	for (int i = 0; i < MAXSIZES; i++)
	{
		//n is size of array to search and sort
		long n = sizes[i];

		//Dynamically allocate array of values and then generate values for it
		
		genValues(x, y, n);
		
		//time the iterative Merge Sort with first array

		//get start
		start = Clock::now().time_since_epoch().count();

		//call function here for time algorithm
		iMergeSort(x, Right, Left);

		//get stop and compute elapsed time
		stop = Clock::now().time_since_epoch().count();
		iMergeelapsedTime = (double)(stop - start);

		//time the recursive Merge Sort with copy of array

		//get start
		start = Clock::now().time_since_epoch().count();

		//call function here for time algorithm
		rMergeSort(y, Right, Left);

		//get stop and compute elapsed time
		stop = Clock::now().time_since_epoch().count();
		rMergeSortelapsedTime = (double)(stop - start);

		//determine key to search for
		int key = x[(int)log(n) + 1];

		//time the iterative Binary search

		//get start
		start = Clock::now().time_since_epoch().count();

		//call function here for time algorithm
		iBinSearch(x, Right, Left, key);

		//get stop and compute elapsed time
		stop = Clock::now().time_since_epoch().count();
		iBinelapsedTime = (double)(stop - start);

		//time the recursive Binary search

		//get start
		start = Clock::now().time_since_epoch().count();

		//call function here for time algorithm
		rBinSearch(y, Right, Left, key);

		//get stop and compute elapsed time
		stop = Clock::now().time_since_epoch().count();
		rBinelapsedTime = (double)(stop - start);

		//output formatted timings
		printPageHeading(outfile);
		printColumnHeadings(outfile, n);

		//sum timings

	}

	// destroys both arrays
	delete[] x;
	delete[] y;

	outfile.close();
	return 0;
}


void openFile(ofstream& outfile) {
	char outfileName[40];

	// ask user for outfile name
	cout << "Enter the output file name: ";
	cin >> outfileName;
	outfile.open(outfileName);
}

//print page and column headings
void printPageHeading(ofstream& outfile) {
	outfile << fixed << setprecision(2) << "Student: Paxton Proctor \n";

}

//print  column headings
void printColumnHeadings(ofstream& outfile, long n) {

}

//generate random values for the array
void genValues(int* x, int* y, long n) {

	//initialize random seed
	srand(time(NULL));
	int value;
	//fill dynamically allocated array with random numbers
	for (int i = 0; i < n; i++) {
		value = rand();
		x[i] = x[value];
	}

	//fill copy dynamically allocated array with random numbers
	for (int j = 0; j < n; j++) {
		y[j] = x[value];
	}
}

//Perform iterative binary search for the key in the array
void iBinSearch(int* x, long left, long right, int key) {
	while (left <= right) {
		int m = left + (right - left) / 2;

		// Check if x is present at mid
		if (x[m] == key) {
			return;
		}
		// If x greater, ignore left half  
		else if (x[m] < key) {
			left = m + 1;
			return;
		}

		// If x is smaller, ignore right half 
		else {
			right = m - 1;
		}
	}
	return;
}

//Perform recursive binary search for the key in the array
void rBinSearch(int* x, long left, long right, int key) {
	if (right >= left) {
		int mid = left + (right - left) / 2;

		// If the element is present at the middle itself
		if (x[mid] == key) {
			return;
		}
		// If element is smaller than mid, then it can only be present
		// in left subarray
		else if (x[mid] > key) {
			rBinSearch(x, left, mid - 1, key);
		}
		// Else the element can only be present in right subarray
		else {
			rBinSearch(x, mid + 1, right, key);
		}
	}
	return;
}

//Perform iterative Merge Sort on the array
void iMergeSort(int* x, long left, long right)
{
	long k;							//index in original array
	long m = (left + right) / 2;	//index of middle
	long n1 = m - left + 1;			//number of elements in 1st subarray
	long n2 = right - m;			//number of elements in 2nd subarray

	//Dynamically allocate arrays for 1st and 2nd halves
	int* L = new int[n1];
	int* R = new int[n2];

	//Copy elements from original array to temp subarrays L[] and R[]
	for (long i = 0; i < n1; i++)
		L[i] = x[left + i];
	for (long j = 0; j < n2; j++)
		R[j] = x[m + 1 + j];

	// Merge the temp arrays back into arr[left..right]

	int i = 0;  // Initial index of first subarray
	int j = 0;  // Initial index of second subarray
	k = left;	// Initial index of merged subarray

	//while more elements in both subarrays
	while (i < n1 && j < n2) {
		//if element in 1st subarray is <= element in 2nd, store in original array
		if (L[i] <= R[j]) {
			x[k] = L[i];
			i++;
		}
		//if element in 2nd subarray is <= element in 1st, store in original array
		else {
			x[k] = R[j];
			j++;
		}

		//increment location in original array
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1) {
		x[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2) {
		x[k] = R[j];
		j++;
		k++;
	}

	//delete dynamically allocated arrays
	delete[] L;
	delete[] R;
}

//Perform recursive Merge Sort on the array
void rMergeSort(int* x, long left, long right) {

	//if 0 or 1 elements in subarray, stop
	if (left >= right)
		return;
	//More than 2 elements in subarray, sort
	else {	//compute middle
		long m = left + (right - left) / 2;

		//sort 1st subarray and sort 2nd subarray
		rMergeSort(x, left, m);
		rMergeSort(x, m + 1, right);

		//merge two sorted subarrays
		Merge(x, left, m, right);
	}
}

//Merge two sorted halves of an array
void Merge(int* x, long left, long m, long right) {

	//determine sizes of two sorted parts
	long n1 = m - left + 1;
	long n2 = right - m;

	// Dynamically allocate temp arrays for both subarrays
	int* L = new int[n1];
	int* R = new int[n2];

	//Copy data to temp arrays L[] and R[]
	for (long i = 0; i < n1; i++)
		L[i] = x[left + i];
	for (long j = 0; j < n2; j++)
		R[j] = x[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]


	long i = 0;		// Initial index of first subarray
	long j = 0;		// Initial index of second subarray
	long k = left;	// Initial index of merged subarray


	//while elements in both subarrays, merge
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			x[k] = L[i];
			i++;
		}
		else {
			x[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of L[], if there are any
	while (i < n1) {
		x[k] = L[i];
		i++;
		k++;
	}

	// Copy remaining elements of R[], if there are any
	while (j < n2) {
		x[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}