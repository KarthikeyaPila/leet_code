#include <stdio.h> 
#include <string.h> 

int countCollisions(char* directions) {
    int len = strlen(directions);
    int collisions = 0;

    int i = 0;
    while(i<len && directions[i] == 'L'){
        i++;
    }

    int j = len-1;
    while(j>=0 && directions[j] == 'R'){
        j--;
    }

    for(int k=i; k<=j; k++){
        if(directions[k] != 'S'){
            collisions++;
        }
    }

    return collisions;
}

int main(){
    char directions[] = "RLRSLL";
    int coll = countCollisions(directions);

    printf("number of collisions: %d\n", coll);

    return 0;
}
