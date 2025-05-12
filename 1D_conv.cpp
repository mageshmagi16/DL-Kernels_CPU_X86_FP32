#include <iostream>
#include <vector>
using namespace std;

int main () {

	std::vector<int> A = {1,2,3,4,5,6};

	std::vector<int> F = {1,0,1};
	
	int stride = 1;

	int output_shape = (A.size() - F.size()) / stride + 1;

	std::vector<int> B(output_shape, 0);

	for (int output_size = 0; output_size < output_shape; output_size++) {
		for (int k= 0; k<3; k++) {
			B[output_size] += A[k + output_size] * F[k];
		}
	}

	for (int output_size = 0; output_size < output_shape; output_size++) {
		std::cout<<B[output_size]<< " ";
	}

	return 0;
}
