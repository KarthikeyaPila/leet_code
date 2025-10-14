#include <stdio.h> 
#include <stdlib.h>

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/

typedef struct{
    int **sum;
	int row;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize){
    NumMatrix *mat = calloc(sizeof(NumMatrix), 1);
    
    mat->sum = calloc(sizeof(int *), matrixSize + 1);
    mat->row = matrixSize;
    
    for(int i=0; i <= matrixSize; i++){
        mat->sum[i] = calloc(sizeof(int), *matrixColSize + 1);
    }

    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<*matrixColSize; j++){
            mat->sum[i+1][j+1] = mat->sum[i+1][j] 
                                            + mat->sum[i][j+1] 
                                            + matrix[i][j] 
                                            - mat->sum[i][j];
        }
    }

    return mat;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2){    
    return obj->sum[row2+1][col2+1] - obj->sum[row1][col2+1] - obj->sum[row2+1][col1] + obj->sum[row1][col1];        
}

void numMatrixFree(NumMatrix* obj){
    for(int i=0; i<=obj->row; i++)
        free(obj->sum[i]);
    free(obj);
}