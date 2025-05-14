#include <stddef.h>

int divide(int dividend, int divisor) {
    if (dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    
    long long div = dividend;
    long long dsor = divisor;
    if (dsor == 0){
        return INT_MAX;  
    } 

    if (dsor && (dsor & (dsor - 1)) == 0) { 
        int shifts = 0;
        while (dsor != 1) {
            dsor >>= 1;
            shifts++;  
        }
        return (int)(div >> shifts);
    }
    
    return (int)(div / dsor);
}