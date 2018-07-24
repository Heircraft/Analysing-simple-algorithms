// Assessment_2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <time.h>
#include <limits>
using namespace std;
const int noOfTests = 50;
//sets the array total size, however each test will only use a portion of it and then the
//subsequent test will overwrite the previous and use a portion more until max is reached
const int N = 25000;
long long numBasicno = 0;
long long randomNumArray[N];
long long min_distance_2(long long A[], double n);
long long max_iteration = 0;
long long resultsAverage[100];

int main() {

	//outer loop determining how many tests are performed
	for (int k = 0; k < 100; k++) {
	    // increment the variable which determines the current input size to be tested
        max_iteration += 250;
        //set the number of basic operations back to zero for each different array size
        numBasicno = 0;
        //inner loop which performs 50 tests which will be averaged for one data point
		for (int j = 0; j < noOfTests; j++) {
			//fills the array to be analysed with random values between 1-N
			for (int i = 0; i < max_iteration; i++) {
				randomNumArray[i] = rand() % (N - 1) + 1;
			}
			//finding the number of basic operations performed and adding it to the
			//total
			numBasicno += min_distance_2(randomNumArray, max_iteration);
		}
		//finding the average number of basic operations performed and storing them in
		//in array
		resultsAverage[k] = numBasicno / noOfTests;

		//printing to screen
		cout << "Average number of basic operations over 50 tests for Array size "
		<< max_iteration << " = " << resultsAverage[k] << endl;

        //print output to file so results may be graphed
		ofstream myfile;
		myfile.open ("efficiencyOutput2.txt",ios::app);
		myfile << max_iteration << "\t" << resultsAverage[k]<< endl;
		myfile.close();
	}
	return 0;
}

long long min_distance_2(long long A[], double n){
    //setting the number of basic operations back to zero every iteration
    long long numBasic = 0;
    int temp;
	long long dmin = std::numeric_limits<double>::infinity();
	for (int d = 0; d < n - 1; d++) {
		for (int f = d + 1; f < n; f++) {
			temp = abs(A[d] - A[f]);
            //adding to the number of basic operations each itearation
			numBasic += 1;
			if (temp < dmin) {
				dmin = temp;
			}
		}
	}
	return numBasic;
}
