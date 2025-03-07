#include <stdio.h> 
#include "solution.h"
#include <assert.h> 

int main(){

    int arr1[4][2] = {{1,3},{2,0},{5,10},{6,-10}};

    int result = findMaxValueOfEquation(arr1[0][0], 4, arr1[0], 1);
    assert (result == 4);
    
    int arr2[4][2] = {{0,0},{3,0},{9,2}};
    result = findMaxValueOfEquation(arr2[0][0], 3, arr2[0], 3);
    assert (result == 3);

    return 0;

}