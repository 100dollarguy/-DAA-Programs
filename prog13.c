//nqueens
//  prog13.c
//  DAA programs
//
//  Created by ROHAN on 31/01/24.
//

#include "prog13.h"
#define N 4
#include <stdbool.h>
#include <stdio.h>

// A utility function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// A utility function to check if a queen can be placed on board[row][col].
// Note that this function is called when "col" queens are already placed in columns from 0 to col - 1,
// so we need to check only the left side for attacking queens.
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

// A recursive utility function to solve N queen problem
bool solveNQUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, then return true
    if (col >= N)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing the queen in board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col] (backtrack)
            board[i][col] = 0;
        }
    }

    // If no queen can be placed in this column, return false
    return false;
}

// This function solves the N Queen problem using Backtracking.
// It mainly uses solveNQUtil to solve the problem.
// It returns false if queens cannot be placed, otherwise, returns true and prints placement of queens.
bool solveNQ() {
    int board[N][N] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

    if (!solveNQUtil(board, 0)) {
        printf("Solution does not exist\n");
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}
