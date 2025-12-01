#include <iostream>
#include "timer.h"
using namespace std;

const int MAX = 400; //Maximum matrix size

// Function to print the matrix.
void printMatrix(int a[][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
// =================== Optimized Rotation ===================
void rotateOptimized(int a[][MAX], int n) {
    // 1. Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    // 2. Reverse each row
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int temp = a[i][l];
            a[i][l] = a[i][r];
            a[i][r] = temp;
            l++;
            r--;
        }
    }
}
// =================== Main Function ===================
int main() {
    int sizes[] = { 10, 50, 100, 200, 300, 400 }; //Different matrix sizes to measure the performance

    cout << "==============================================\n";
    cout << "   Matrix Rotation Time Measurement (µs)\n";
    cout << "==============================================\n";
    cout << "Size\tExecution Time (µs)\n";
    cout << "----------------------------------------------\n";

    for (int s = 0; s < 6; s++) {
        int n = sizes[s];
        int a[MAX][MAX]; //Static matrix with maximum size(n*n)

        //Automatically fill the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 1;  // أو rand() % 100
            }
        }

        Timer t;
        t.start();

        //Repeat the operation multiple times to get clearer timing
        for (int repeat = 0; repeat < 500; repeat++) {
            rotateOptimized(a, n);
        }
        t.stop();

        double duration = t.getDurationMicro();
        cout << n << "x" << n << "\t" << duration << "\n";
    }
    cout << "==============================================\n";
    return 0;
}

