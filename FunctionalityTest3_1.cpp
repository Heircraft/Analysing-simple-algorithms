


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

//length of array to be analysed
const int N = 15;
//function declaration
double min_distance_1(int A[], double n);

int main() {
	//the values being hard coded into the array being analysed
	int A[N] = {34,95,77,68,4,42,1,100,74,85,19,37,94,31,9};
	//printing out the answer
	cout << "Greatest Magnitude of Difference = " << min_distance_1(A, N) << endl;

	return 0;
}

double min_distance_1(int A[], double n){
    double dmin = std::numeric_limits<double>::infinity();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i != j) && ((abs(A[i] - A[j])) < dmin)) {
				dmin = abs(A[i] - A[j]);
			}
		}
	}
	return dmin;
}
