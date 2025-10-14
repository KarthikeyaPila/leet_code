#include <stdio.h>
#include <stdbool.h>

bool matrix_3x3(char **board, int startRow, int startCol){
    int hash[10]={0};

    for (int i=startRow; i<startRow+3; i++){
        for (int j =startCol; j<startCol+3; j++){
            char c = board[i][j];
            if (c != '.'){
                int num = c - '0';
                if (hash[num]) return false;
                hash[num]=1;
            }
        }
    }

    return true;
}


bool check_rows(char **board, int boardSize, int *columns) {
    int cols = *columns;

    for (int i = 0; i < boardSize; i++) {
        int hash[10] = {0};
        for (int j = 0; j < cols; j++) {
            char c = board[i][j];
            if (c != '.') {
                int num = c - '0';
                if (hash[num]) return false;
                hash[num] = 1;
            }
        }
    }

    return true;
}


bool check_cols(char **board, int boardSize, int *columns) {
    int cols = *columns;

    for (int i = 0; i < cols; i++) {
        int hash[10] = {0};
        for (int j = 0; j < boardSize; j++) {
            char c = board[j][i];
            if (c != '.') {
                int num = c - '0';
                if (hash[num]) return false;
                hash[num] = 1;
            }
        }
    }

    return true;
}


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if (!check_rows(board, boardSize, boardColSize)){
        return false;
    }

    if (!check_cols(board, boardSize, boardColSize)){
        return false;
    } 

    for (int i = 0; i < boardSize; i += 3) {
        for (int j = 0; j < *boardColSize; j += 3) {
            if (!matrix_3x3(board, i, j)){
                return false;
            }
        }
    }

    return true;
}
