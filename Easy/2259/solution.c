#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int string_to_int(char *arr){
    int num=0;

    for(int i = strlen(arr)-1, j=0; i>=0; i--, j++){

        num += (arr[i] - '0')*pow(10, j);
    
    }

    return num;
}

char* removeDigit(char* num_arr, char digit) {
    int len = strlen(num_arr);
    char* max_result = (char*)malloc(len);
    max_result[0] = '\0';

    for (int i = 0; i < len; i++) {
        if (num_arr[i] == digit) {
            char temp[101];
            int idx = 0;

            for (int j = 0; j < len; j++) {
                if (j != i) {
                    temp[idx++] = num_arr[j];
                }
            }
            temp[idx] = '\0';

            if (strcmp(temp, max_result) > 0) {
                strcpy(max_result, temp);
            }
        }
    }
}

// "32998589353917872714814599237991174513476623756395992135212546127959342974628712329595771672911914471"