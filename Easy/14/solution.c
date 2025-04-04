#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int len) {

    if (len == 0){
        return "";
    }

    int minLength = strlen(strs[0]);

    for (int i = 1; i < len; i++){
        int currentLength = strlen(strs[i]);
        if(currentLength < minLength){
            minLength = currentLength;
        }
    }

    char* sol_arr = (char*)malloc((minLength + 1) * sizeof(char));
    if(!sol_arr){
        return "";
    } 
    
    int i = 0;

    while (i < minLength) {
        char current_char = strs[0][i];
        
        for (int j = 1; j < len; j++) {
            if (strs[j][i] != current_char) { 
                sol_arr[i] = '\0';
                return sol_arr;
            }
        }
        
        sol_arr[i] = current_char;
        i++;
    }

    sol_arr[i] = '\0';
    return sol_arr;
}