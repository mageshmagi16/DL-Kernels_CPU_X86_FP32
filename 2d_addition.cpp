#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<std::vector<int>> A = {
	{1,2},
	{3,4}
	};
	
	std::vector<std::vector<int>> B = {
	{1,1},
	{1,1}
	};

	std::vector<std::vector<int>> C(2, std::vector<int>(2));
		
	for (int i = 0; i<2; i++) {
		for (int j = 0; j <2; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	for (int i = 0; i <2; i++) {
		for (int j=0; j<2; j++) {
			std::cout<<C[i][j] <<" ";
		}
		std::cout << std::endl;
	}

	return 0;

}
