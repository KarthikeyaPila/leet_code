#include <stdio.h> 
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t){

    if(strlen(s)!=strlen(t)){
      return false;
    }  
  
    int hash1[26] ={0};
    int hash2[26]={0};
  
    for(int i=0;s[i]!='\0';i++){
        hash1[s[i]-'a']++;
        hash2[t[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(hash1[i]!=hash2[i]){
            return false;
        }
    }
    return true;
}
  
int main(){
    char str1[] = "anagram";
    char str2[] = "nagaram";

    if(isAnagram(str1, str2)){
        printf("they are anagrams\n");
    } else {
        printf("they are NOT anagrams\n");
    }

    return 0;
}