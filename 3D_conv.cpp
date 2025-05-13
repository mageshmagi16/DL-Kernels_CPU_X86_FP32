#include <iostream>
#include <vector>
using namespace std;

int main() {

	std::vector<std::vector<std::vector<int>>> A = {
        {
    	    {1,2,3},
    	    {4,5,6},
    	    {7,8,9}
        },
        {            
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
    	}
	};

	std::vector<std::vector<std::vector<int>>> F = {
        {
            {1, 0},
            {0, 1}
        },
        {
            {0, 1},
            {1, 0}
        }
    };

	int stride = 1;
    int num_filters = 1;
    int input_depth = 2;

    int input_size = A[0].size();      
    int filter_size = F[0].size();    
    int output_size = (input_size - filter_size) / stride + 1;

    std::vector<std::vector<std::vector<int>>> C(num_filters, std::vector<std::vector<int>>(output_size, std::vector<int>(output_size, 0)));

    for (int out_z = 0; out_z < num_filters; out_z++) {
        for (int out_x = 0; out_x < output_size; out_x++) {
            for (int out_y = 0; out_y < output_size; out_y++) {
                C[out_z][out_x][out_y] = 0;
                for (int kz = 0; kz < input_depth; kz++) {
                    for (int kx = 0; kx < filter_size; kx++) {
                        for (int ky = 0; ky < filter_size; ky++) {
                            int irow = out_x * stride + kx;
                            int icol = out_y * stride + ky;
                            C[out_z][out_x][out_y] += A[kz][irow][icol] * F[kz][kx][ky];
                        }
                    }
                }
            }
        }
    }

     for (int out_z = 0; out_z < num_filters; out_z++) {
        for (int out_x = 0; out_x < output_size; out_x++) {
            for (int out_y = 0; out_y < output_size; out_y++) {
                std::cout << C[out_z][out_x][out_y] << " ";
            }
            std::cout << endl;
        }
        std::cout << endl;
    }
    
    
    return 0;

}