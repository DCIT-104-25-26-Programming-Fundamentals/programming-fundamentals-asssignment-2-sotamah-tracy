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

void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int source[10][10], int target[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            target[j][i] = source[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int matrix1[10][10];
    int matrix2[10][10];
    int result[10][10];
    int transpose[10][10];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    readMatrix(matrix1, rows, cols);

    cout << endl << "Original Matrix:" << endl;
    displayMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, transpose, rows, cols);
    cout << endl << "Transposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);

    cout << endl;
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter number of rows for matrix 1: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix 1: ";
    cin >> colsA;
    readMatrix(matrix1, rowsA, colsA);

    cout << "Enter number of rows for matrix 2: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix 2: ";
    cin >> colsB;
    readMatrix(matrix2, rowsB, colsB);

    if (rowsA != rowsB || colsA != colsB)
    {
        cout << "Error: Matrices must have the same dimensions for addition." << endl;
    }
    else
    {
        addMatrices(matrix1, matrix2, result, rowsA, colsA);
        cout << endl << "Sum of matrices:" << endl;
        displayMatrix(result, rowsA, colsA);
    }

    cout << endl;
    cout << "Enter number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;
    readMatrix(matrix1, rowsA, colsA);

    cout << "Enter number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;
    readMatrix(matrix2, rowsB, colsB);

    if (colsA != rowsB)
    {
        cout << "Error: Number of columns in A must equal number of rows in B for multiplication." << endl;
    }
    else
    {
        multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, colsB);
        cout << endl << "Product of matrices:" << endl;
        displayMatrix(result, rowsA, colsB);
    }

    return 0;
}

