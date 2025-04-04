#include <stdio.h> 
#include <string.h>

char* intToRoman(int num) {
    char result[20];
    result[0] = '\0';

    char *symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i=0; i<13; i++) {
        while (num >= value[i]) {
            strcat(result, symbol[i]);
            num -= value[i];
        }
    }

    return result;
}