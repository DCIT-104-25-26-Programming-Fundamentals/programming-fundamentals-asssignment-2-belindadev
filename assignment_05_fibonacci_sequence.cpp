// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;



// Function for PART A: Print the first N terms of the Fibonacci sequence
void printFirstNTerms() {
    int N;
    cout << "How many terms? ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";
    
    long long a = 0, b = 1;

    for (int i = 0; i < N; i++) {
        cout << a << " ";
        long long nextTerm = a + b;
        a = b;
        b = nextTerm;
    }
    cout << endl;
}

// Function for PART B: Check if a number belongs to the Fibonacci sequence
void checkIfFibonacci() {
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;

    if (num < 0) {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }

    long long a = 0, b = 1;
    bool isFibonacci = false;

    // Generate Fibonacci numbers iteratively using a loop until reaching or exceeding num
    while (a <= num) {
        if (a == num) {
            isFibonacci = true;
            break;
        }
        long long nextTerm = a + b;
        a = b;
        b = nextTerm;
    }

    if (isFibonacci) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    // Execute Part A
    printFirstNTerms();
    cout << endl;

    // Execute Part B
    checkIfFibonacci();

    return 0;
}