#include <stdio.h> 
#include <string.h>
#include "solution.h"
#include <math.h>

int main(){
    char num_string[] = {"21914471"};
    char num = '1';

    char *arr = removeDigit(num_string, num);

    printf("Number: %s\n", arr);
    return 0;
}