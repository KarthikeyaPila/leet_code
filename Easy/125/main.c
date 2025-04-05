#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *basic_string(char * arr){
    int len = strlen(arr);
    char *string = (char *)malloc(len+1);
    int j=0;

    for(int i=0; i<len; i++){
        if(arr[i] >= 'a' && arr[i] <= 'z'){
            string[j] = (char)arr[i];
            j++;
        }

        else if(arr[i] >= 'A' && arr[i] <= 'Z'){
            string[j++] = arr[i] + 32;
        } 

        else if((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= '0' && arr[i] <= '9')) {
            string[j++] = arr[i];
        }
    }

    string[j] = '\0';
    return string;
}

bool isPalindrome(char* string){

    char *arr = basic_string(string);

    if(strlen(arr) == 0){
        return true;
    }

    int len = strlen(arr);

    char *left = &arr[0];
    char *right = &arr[len-1];

    while(left < right){
        if(*left != *right){
            return false;
            break;
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    
    char string[] = "A man, a plan, a canal: Panama";

    if(isPalindrome(string)){
        printf("it is a palindrome\n");
    } else {
        printf("it is not a palindrome\n");
    }

    return 0;
}