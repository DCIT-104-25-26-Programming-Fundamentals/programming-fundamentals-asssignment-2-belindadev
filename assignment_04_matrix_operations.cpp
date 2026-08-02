// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;




const int MAX_SIZE = 10;

// Helper function to input a matrix
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// ==========================================
// PART A - Transpose a Matrix
// ==========================================
void partA_Transpose() {
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];

    cout << "\n--- PART A: Transpose Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nInput Matrix Elements:" << endl;
    inputMatrix(matrix, rows, cols);

    // Compute Transpose (rows become columns, columns become rows)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);
}

void partB_Add() {
    int rows, cols;
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int sum[MAX_SIZE][MAX_SIZE];

    cout << "\n--- PART B: Matrix Addition ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nInput Matrix A:" << endl;
    inputMatrix(A, rows, cols);

    cout << "\nInput Matrix B:" << endl;
    inputMatrix(B, rows, cols);

    // Compute element-wise sum
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nResultant Matrix (A + B):" << endl;
    displayMatrix(sum, rows, cols);
}


void partC_Multiply() {
    int M, N, P;
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int product[MAX_SIZE][MAX_SIZE] = {0};

    cout << "\n--- PART C: Matrix Multiplication ---" << endl;
    cout << "Enter rows for Matrix A (M): ";
    cin >> M;
    cout << "Enter columns for Matrix A / rows for Matrix B (N): ";
    cin >> N;
    cout << "Enter columns for Matrix B (P): ";
    cin >> P;

    cout << "\nInput Matrix A (" << M << " x " << N << "):" << endl;
    inputMatrix(A, M, N);

    cout << "\nInput Matrix B (" << N << " x " << P << "):" << endl;
    inputMatrix(B, N, P);

    // Matrix multiplication: A (M x N) * B (N x P) = Product (M x P)
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            product[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResultant Product Matrix (A x B):" << endl;
    displayMatrix(product, M, P);
}

int main() {
    // Run each operation sequentially
    partA_Transpose();
    partB_Add();
    partC_Multiply();

    return 0;
}