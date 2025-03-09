#include <stdio.h>
// #include <assert.h>
#include "solution.h"

int main(){
    int x0[] = {1,3};
    int x1[] = {2,0};
    int x2[] = {5,10};
    int x3[] = {6,-10};
    // int arr1[4][2] = {{1,3},{2,0},{5,10},{6,-10}};
    int* arr1[4] = {x0, x1, x2, x3};

    int result = findMaxValueOfEquation((int**)arr1, 4, arr1[0], 1);
    result == 4 ? printf("PASS result == 4\n"): fprintf(stderr, "FAIL result == 4\n");

    return 0;
}
