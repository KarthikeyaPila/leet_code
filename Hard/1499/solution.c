#include <stdio.h> 
#include "solution.h"

int findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k) {
    int max = 0; 
    int abs_max = 0;
// max = yi + yj + |xi - xj|   
// |xi - xj| <= k

    for(int i=0; i<pointsSize; i++){
        for(int j=i; j<pointsSize; j++){
            int mod = points[i][0] + points[j][0];
            mod = mod < 0 ? mod*-1 : mod;

            if(mod <= k){
                max = points[i][1] + points[j][1] + mod;
            }

            if(max > abs_max){
                abs_max = max; 
            }
        }
    }

    return abs_max;
}
