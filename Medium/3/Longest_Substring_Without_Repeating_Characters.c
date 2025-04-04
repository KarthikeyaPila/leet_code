#include <stdio.h>
#include <string.h>
int lengthOfLongestSubstring(char *s) {
    int charIndex[128] = {0};
    int start = 0, maxLength = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        char currentChar = s[end];

        if (charIndex[currentChar] > start) {
            start = charIndex[currentChar];
        }

        charIndex[currentChar] = end + 1;

        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main(){
    char str[10000];
    printf("enter the string");
    scanf("%s", str);
    int length = lengthOfLongestSubstring(str);
    printf("%d", length);
    return 0;
}
