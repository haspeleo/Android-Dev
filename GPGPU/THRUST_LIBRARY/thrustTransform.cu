#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <thrust/transform.h>

#include <thrust/sequence.h>
#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/replace.h>

#include <thrust/functional.h>

#include "utils.h"
#include <algorithm>

int op_negate(int i) {return -1 * i;}

int main () {

    // allocate three device_vectors with 10 elements
    	thrust::device_vector<int> X(10);
	thrust::device_vector<int> Y(10);
	thrust::device_vector<int> Z(10);

	printDeviceVector(X, "X");
	
    // initialize X to 0,1,2,3, ....
	thrust::sequence (X.begin(), X.end());
	printDeviceVector(X, "X");
    // compute Y = -X
	std::transform(X.begin(), X.end(), Y.begin(), op_negate);
	
	printDeviceVector(X, "X");
    // fill Z with twos

    // compute Y = X mod 2

    // replace all the ones in Y with tens

    // print Y
	
return 0;
}
