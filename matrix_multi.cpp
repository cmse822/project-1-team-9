#include <iostream>
#include <vector>
#include <chrono>
#include "get_walltime.c" // You should have this file for timing

using namespace std;

// Function to perform matrix multiplication
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
    const int N = 30; // Matrix size

    // Initialize matrices A and B (random values for simplicity)
    vector<vector<float>> A(N, vector<float>(N, 1.0));
    vector<vector<float>> B(N, vector<float>(N, 2.0));

    double start_time;
    get_walltime(&start_time);

    vector<vector<float>> result = matrixMultiply(A, B);

    double end_time;
    get_walltime(&end_time);

    double elapsed_time = end_time - start_time;

    // Calculate performance in Mflop/s
    double total_ops = 2.0 * N * N * N; // Assuming standard matrix multiplication
    double mflops = (total_ops / elapsed_time) * 1e-6;

    // Output results
    cout << "Matrix Size (N): " << N << endl;
    cout << "Time measured: " << elapsed_time << " seconds." << endl;
    cout << "Performance: " << mflops << " Mflop/s" << endl;

    return 0;
}