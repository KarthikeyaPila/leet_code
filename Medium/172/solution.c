#include <stdio.h> 

int trailingZeroes(int num) {
    int five_count = 0; 

    while(num != 0){
        five_count += num/5;
        num /= 5; 
    }   

    return five_count; 
}