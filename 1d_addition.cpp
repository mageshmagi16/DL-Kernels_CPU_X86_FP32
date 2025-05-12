#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::vector<int> A = {1,2,3};
	std::vector<int> B = {1,1,1};

	std::vector<int> C(3);
	
	for (int i = 0; i < 3; i++) {
		C[i] = A[i] + B[i];
	}

	for (int i = 0; i <3; i++) {
		std::cout<< C[i]<< " ";
	}

	return 0;
}
