#include <stdio.h>
#include "solution.h"

int main(){
    int children_rank[] = {1,0,2};
    int no_of_children = sizeof(children_rank)/sizeof(int);

    int min_candy = candy(children_rank, no_of_children);

    printf("min candies: %d\n", min_candy);

    return 0;
}