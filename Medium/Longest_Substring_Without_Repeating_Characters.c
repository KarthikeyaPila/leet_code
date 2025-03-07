#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    int charIndex[128] = {0}; // Array to store last seen index + 1 of characters
    int start = 0, maxLength = 0; // Initialize pointers and max length

    for (int end = 0; s[end] != '\0'; end++) { // Iterate over the string
        char currentChar = s[end];

        // If the current character has been seen and is within the window
        if (charIndex[currentChar] > start) {
            start = charIndex[currentChar]; // Move start right after the last occurrence
        }

        // Update the last seen index (+1 to handle index 0)
        charIndex[currentChar] = end + 1;

        // Update the max length of the substring
        int currentLength = end - start + 1; // Calculate the window size
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength; // Return the longest length found
}

int main(){
    char str[10000];
    printf("enter the string");
    scanf("%s", str);
    int length = lengthOfLongestSubstring(str);
    printf("%d", length);
    return 0;
}
