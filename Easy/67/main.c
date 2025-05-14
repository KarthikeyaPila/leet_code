#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b){
  size_t lenA = strlen(a);
  size_t lenB = strlen(b);
  size_t len = lenA > lenB ? lenA : lenB;

  if(lenA == 0 || lenB == 0){
    return NULL;
  }

  char* result = (char*)malloc(sizeof(char) * (len + 2));
  result[len + 1] = '\0';

  int carry = 0;
  int i = (int)lenA - 1;
  int j = (int)lenB - 1;
  int k = (int)len;

  while (k >= 0){
    int bitA = i >= 0 ? a[i--] - '0' : 0;
    int bitB = j >= 0 ? b[j--] - '0' : 0;

    int sum = bitA + bitB + carry;
    result[k--] = (sum % 2) + '0';
    carry = sum / 2;
  }

  if (result[0] == '1'){
    return result;
  } else {
    char* trimmed = result + 1;
    char* final = strdup(trimmed);
    free(result);
    return final;
  }
}

int main(){
  char a[100] = "1";
  char b[100] = "11";

  printf("%s\n", addBinary(a, b));

  return 0;
}
