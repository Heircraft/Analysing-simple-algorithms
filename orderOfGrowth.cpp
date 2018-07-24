// Assessment_2.cpp : Defines the entry point for the console application.
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <limits>
using namespace std;
const int noOfTests = 50;
//sets the array total size, however each test will only use a portion of it and then the
//subsequent test will overwrite the previous and use a portion more until max is reached
const int N = 25000;
int randomNumArray[N];
double min_distance_1(int A[], double n);
double max_iteration = 0;
double execTimes = 0;
double execTimesAverage[100];

int main() {

	//outer loop determining how many tests are performed
	for (int k = 0; k < 100; k++) {
	    // increment the variable which determines the current input size to be tested
        max_iteration += 250;
        //set the number of basic operations back to zero for each different array size
        execTimes = 0;
        //inner loop which performs 50 tests which will be averaged for one data point
		for (int j = 0; j < noOfTests; j++) {
			//fills the array to be analysed with random values between 1-N
			for (int i = 0; i < max_iteration; i++) {
				randomNumArray[i] = rand() % (N - 1) + 1;
			}

            //store the start time of the algorithm
            clock_t start_clock = clock();
            //running the algorithm with the random array and its size as inputs
            min_distance_1(randomNumArray, max_iteration);
            //store the end time of the algorithm
            clock_t end_clock = clock();

            //find the difference to determine time taken for algorithm and
            //additively store values
            execTimes += (end_clock - start_clock) / double(CLOCKS_PER_SEC);
		}
		//find the average of all execution times for this data point
		 execTimesAverage[k] = execTimes / noOfTests;

        //print the results to screen
		cout << "Average execution time over 50 tests for Array size "
		<< max_iteration << " = " << fixed << setprecision(5) << execTimesAverage[k]
		<< "s" << endl;

        //print output to file so results may be graphed
		ofstream myfile;
		myfile.open ("orderOfGrowthOutput.txt",ios::app);
		myfile << max_iteration << "\t" << execTimesAverage[k]<< endl;
		myfile.close();
	}
	return 0;
}

double min_distance_1(int A[], double n){
    //dmin is set to infinity purely as a starting point to it is impossible for
    //anything to be greater than it
    double dmin = std::numeric_limits<double>::infinity();
    //the first an outer loop which iterates through the entire array
	for (int i = 0; i < n; i++) {
        //the inner loop which also iterates throug the entire array
		for (int j = 0; j < n; j++) {
		    //an if statement which ensures that the two elements compared are not
		    //the same to prevent dmin from = zero. Then returns dmin if
		    //the magnitude of the difference of the two current elements is less
		    //than what dmin currently holds
			if ((i != j) && ((abs(A[i] - A[j])) < dmin)) {
			    //the old value of dmin is overrided with a new smaller magnitude
			    //of difference
				dmin = abs(A[i] - A[j]);
			}
		}
	}
	//returns dmin
	return dmin;
}
