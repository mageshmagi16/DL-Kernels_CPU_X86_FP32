#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<std::vector<int>> A = {

	{1, 2},
	{3, 4}
	};

	std::vector<std::vector<int>> B(2, std::vector<int>(2));

	for (int i = 0; i <2; i ++) {
		for(int j=0; j<2; j++) {
			B[i][j] = A[j][i];
		}
	}

	for (int i= 0; i<2; i++) {
		for(int j=0; j<2; j++) {
			std::cout<<B[i][j]<< " ";
		}
	std::cout<<endl;
	}

	return 0;
}
