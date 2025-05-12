
#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<std::vector<int>> A = {
	{1,2,3},
	{4,5,6},
	{7,8,9}
	};

	std::vector<std::vector<int>> F = {
	{1,0},
	{0,1}
	};

	int stride = 1;
	
	int output_size = (A.size() - F.size()) / stride + 1;

	std::vector<std::vector<int>>C(output_size, std::vector<int>(output_size, 0));

	for (int out_x = 0; out_x < output_size; out_x++) {
		for (int out_y = 0; out_y < output_size; out_y++) {
			C[out_x][out_y] = 0;
			
			for (int kx = 0; kx < F.size(); kx++) {
				for (int ky = 0; ky < F.size(); ky++) {
					int irow = out_x * stride + kx;
					int icol = out_y * stride + ky;
					C[out_x][out_y] += A[irow][icol] * F[kx][ky];
				}
			}
		}
	}	
	

	for (int out_x = 0; out_x < output_size; out_x++) {
		for (int out_y = 0; out_y < output_size; out_y++) {
			std::cout<<C[out_x][out_y]<< " ";
		}
		std::cout<<endl;
	}

	return 0;

}
