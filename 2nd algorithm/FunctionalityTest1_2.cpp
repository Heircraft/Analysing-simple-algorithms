


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
double min_distance_2(int A[], double n);

int main() {
	//the values being hard coded into the array being analysed
	int A[N] = {1,3,6,10,15,21,28,36,45,55 };
	//printing out the answer
	cout << "Greatest Magnitude of Difference = " << min_distance_2(A, N) << endl;

	return 0;
}

double min_distance_2(int A[], double n){
    int temp;
    // Reset dmin to infinity for second algorithm
	double dmin = std::numeric_limits<double>::infinity();
	for (int d = 0; d < n - 1; d++) {
		for (int f = d + 1; f < n; f++) {
			temp = abs(A[d] - A[f]);
			if (temp < dmin) {
				dmin = temp;
			}
		}
	}
	return dmin;
}
