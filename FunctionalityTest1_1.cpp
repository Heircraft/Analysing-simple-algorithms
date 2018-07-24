


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
const int N = 10;
//function declaration
double min_distance_1(int A[], double n);

int main() {
	//the values being hard coded into the array being analysed
	int A[N] = {1,3,6,10,15,21,28,36,45,55 };
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
