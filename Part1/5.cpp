#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include "matplotlibcpp.h"

#define MAX_N 10000000
#define NUM_REPEATS 100

namespace plt = matplotlibcpp;

using std::cout; using std::endl;
using std::mt19937_64; using std::uniform_int_distribution; using std::random_device;

int main(void) {
    // Initialize matplotlibcpp for plotting
    plt::backend("Agg");

    // Prepare vectors for plotting
    std::vector<double> matrixSizes;
    std::vector<double> gflops;

    // Loop over matrix sizes
    for (int currentN = 1; currentN <= MAX_N; currentN *= 10) {
        float mat1[currentN][currentN];
        float mat2[currentN][currentN];

        // Populate matrices with random values
        random_device rd;
        mt19937_64 prng(rd());
        uniform_int_distribution<int> dist(0, 256);
        for (int i = 0; i < currentN; i++) {
            for (int j = 0; j < currentN; j++) {
                mat1[i][j] = prng() / 256 - 0.5;
                mat2[i][j] = prng() / 256 - 0.5;
            }
        }

        // Matrix multiplication and performance measurement
        float rslt[currentN][currentN];
        auto start_time = std::chrono::high_resolution_clock::now();
        for (int iter = 0; iter < NUM_REPEATS; iter++) {
            for (int i = 0; i < currentN; i++) {
                for (int j = 0; j < currentN; j++) {
                    rslt[i][j] = 0;
                    for (int k = 0; k < currentN; k++) {
                        rslt[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;

        // Calculate total FLOPs and Gflop/s
        double total_flops = 2.0 * currentN * currentN * currentN * NUM_REPEATS; // Assuming each multiplication and addition is a FLOP
        double gflops_per_second = total_flops / (elapsed_seconds.count() * 1e9);

        // Store results for plotting
        matrixSizes.push_back(currentN);
        gflops.push_back(gflops_per_second);
    }

    // Plot the results
    plt::plot(matrixSizes, gflops);
    plt::xlabel("Matrix Size (N)");
    plt::ylabel("Gflop/s");
    
    // Assuming ClockSpeed is the clock speed of your system
    double ClockSpeed = 3.5; // Replace with your system's clock speed in GHz
    double theoreticalPeakPerformance = ClockSpeed * 1e9; // Convert GHz to Hz
    plt::axhline(theoreticalPeakPerformance, "--r", "Theoretical Peak Performance");

    plt::title("Measured Gflop/s vs. Matrix Size");
    plt::grid(true);
    plt::save("performance_plot.png");
}
