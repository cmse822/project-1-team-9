#include <iostream>
#include <vector>
#include <chrono>
#include "get_walltime.c"

using namespace std;

vector<vector<float>> matrixMultiply(const vector<vector<float>>& A, const vector<vector<float>>& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();

    vector<vector<float>> C(rows_A, vector<float>(cols_B, 0.0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    const int N = 1000; // Matrix size
    const int num_iterations = 10; // Number of iterations

    // Initialize matrices A and B (random values for simplicity)
    vector<vector<float>> A(N, vector<float>(N, 1.0));
    vector<vector<float>> B(N, vector<float>(N, 2.0));

    double total_elapsed_time = 0;

    for (int iteration = 0; iteration < num_iterations; ++iteration) {
        double start_time;
        get_walltime(&start_time);

        vector<vector<float>> result = matrixMultiply(A, B);

        double end_time;
        get_walltime(&end_time);

        total_elapsed_time += (end_time - start_time);
    }

    double average_elapsed_time = total_elapsed_time / num_iterations;

    // Calculate performance in Mflop/s
    double total_ops = 2.0 * N * N * N ; // Total ops for all iterations
    double gflops = (total_ops / average_elapsed_time) * 1e-9;

    // Output results
    cout << "Matrix Size (N): " << N << endl;
    cout << "Average Time per Iteration: " << average_elapsed_time << " seconds." << endl;
    cout << "Average Performance: " << gflops << " Gflop/s" << endl;

    return 0;
}




