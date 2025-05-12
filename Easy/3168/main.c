#include <stdio.h> 
#include <string.h>

int minimumChairs(char* s) {
    int max_chairs = 0;
    int inside = 0;

    for(int i=0; i<strlen(s); i++){

        if(s[i] == 'E'){
            inside++;
            if(max_chairs < inside){
                max_chairs++;
            }
        } else if(s[i] == 'L'){
            inside--;
        }
    }

    return max_chairs;
}

