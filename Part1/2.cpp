#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <chrono>
#define N 100

using std::cout; using std::endl;
using std::mt19937_64; using std::uniform_int_distribution; using std::random_device;

int main(void) {
    float mat1[N][N];
    float mat2[N][N];
    random_device rd;
    mt19937_64 prng(rd());
    uniform_int_distribution<int> dist(0, 256);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat1[i][j] = prng() / 256 - 0.5;
            mat2[i][j] = prng() / 256 - 0.5;
            printf("%f\t", mat1[i][j]);
        }
    }

    float rslt[N][N];
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int iter = 0; iter < NUM_REPEATS; iter++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rslt[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    rslt[i][j] += mat1[i][k] * mat2[k][j];
                }
                printf("%f\t", rslt[i][j]);
            }
            printf("\n");
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end_time - start_time;

    // Calculate total FLOPs and Mflop/s
    double total_flops = 2.0 * N * N * N * NUM_REPEATS; // Assuming each multiplication and addition is a FLOP
    double mflops_per_second = total_flops / (elapsed_seconds.count() * 1e6);

    cout << "Total Execution Time: " << elapsed_seconds.count() << " seconds" << endl;
    cout << "Total FLOPs: " << total_flops << endl;
    cout << "Performance: " << mflops_per_second << " Mflop/s" << endl;

    return 0;
}
