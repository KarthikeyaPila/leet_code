#include <stdio.h> 
#include <string.h>
#include "solution.h"

int main() {
    char* strs[] = {"flower", "floww", "flight"};
    int len = sizeof(strs) / sizeof(strs[0]);
    
    char* result = longestCommonPrefix(strs, len);

    printf("%s\n", result);
    return 0;
}