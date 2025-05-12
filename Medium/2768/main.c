#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

// m, n => dimensions of a grid.
// coordinates => x,y -> all are black
// the coordinates that are not present in coordinates are all white.

long long* countBlackBlocks(int m, int n, int** coordinates, int coordinatesSize, int* coordinatesColSize, int* returnSize) {
    long long *arr = (long long *)calloc(5, sizeof(long long));
    *returnSize = 5;

    int** virtual_arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        virtual_arr[i] = (int*)calloc(n, sizeof(int));  // initializes to 0
    }

    for(int i=0; i<coordinatesSize; i++){
        int x = coordinates[i][0];
        int y = coordinates[i][1];

        virtual_arr[x][y] = 1;
    }

    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            int count = 0;  
            // 2x2 coordinates: i,j  i+1,j  i,j+1, i+1,j+1
            //wheever i detect a black in a 2x2 box i count++
            if(virtual_arr[i][j] == 1){
                count++;
            }
            if(virtual_arr[i+1][j] == 1){
                count++;
            }
            if(virtual_arr[i][j+1] == 1){
                count++;
            }
            if(virtual_arr[i+1][j+1] == 1){
                count++;
            }
            arr[count]++;
        }
    }

    for (int i = 0; i < m; i++) {
        free(virtual_arr[i]);
    }
    free(virtual_arr);

    return arr;
}


// // solution 2;
// long long* countBlackBlocks(int m, int n, int** coordinates, int coordinatesSize, int* coordinatesColSize, int* returnSize) {
//     long long *arr = (long long *)calloc(5, sizeof(long long));
//     *returnSize = 5;

    
    
//     for(int i=0; i<coordinatesSize; i++){
//         for(int j=0; j<coordinatesSize; j++){
//             int count=0;

//             //i,j  i+1,j  i,j+1, i+1,j+1
//             if(coordinates[i][0] == coordinates[j][0]){
//                 count++;
//             }
//             if(coordinates[i+1][0] == coordinates[j][0]){
//                 count++;
//             }
//             if(coordinates[i][0] == coordinates[j+1][0]){
//                 count++;
//             }
//             if(coordinates[i+1][0] == coordinates[j+1][0]){
//                 count++;
//             }


//             // whenever two coords have a distance of 1: black++
//             // then after we'll update it to the array.
//         }
//     }
// }


//gpt's answer

// #include <stdlib.h>
// #include <string.h>

// #define HASH_SIZE 262144  // should be much bigger than coordinatesSize for low collision

// typedef struct {
//     long long key;    // block ID = x * n + y
//     int count;  // number of black cells in this block
//     int used;   // flag for occupied slot
// } Block;

// long long* countBlackBlocks(int m, int n, int** coordinates, int coordinatesSize, int* coordinatesColSize, int* returnSize) {
//     long long* result = (long long*)calloc(5, sizeof(long long));
//     *returnSize = 5;

//     Block* hashTable = (Block*)calloc(HASH_SIZE, sizeof(Block));

//     int dirs[4][2] = {{0,0},{-1,0},{0,-1},{-1,-1}};

//     for (int i = 0; i < coordinatesSize; i++) {
//         int x = coordinates[i][0];
//         int y = coordinates[i][1];

//         for (int d = 0; d < 4; d++) {
//             int nx = x + dirs[d][0];
//             int ny = y + dirs[d][1];

//             if (nx >= 0 && ny >= 0 && nx < m - 1 && ny < n - 1) {
//                 long long key = (long long)nx * n + ny;
//                 int h = key % HASH_SIZE;
//                 if (h < 0) h += HASH_SIZE;

//                 while (hashTable[h].used && hashTable[h].key != key) {
//                     h = (h + 1) % HASH_SIZE;
//                 }

//                 if (!hashTable[h].used) {
//                     hashTable[h].used = 1;
//                     hashTable[h].key = key;
//                     hashTable[h].count = 1;
//                 } else {
//                     hashTable[h].count += 1;
//                 }
//             }
//         }
//     }

//    long long totalBlocks = (long long)(m - 1) * (n - 1);

//     int seen = 0;

//     for (int i = 0; i < HASH_SIZE; i++) {
//         if (hashTable[i].used) {
//             result[hashTable[i].count]++;
//             seen++;
//         }
//     }

//     result[0] = (long long)(totalBlocks - seen);
//     free(hashTable);
//     return result;
// }



int main(){
    int coordinates[3][2] = {
        {0,0},{1,1},{0,2}
    };

    long long *arr = countBlackBlocks(3, 3, coordinates, 3, 2, )

    printf("hello world!\n");

    return 0;
}


// [[0,0],[1,1],[0,1],[0,2]] =>  {0,2,0,2,0,0}








