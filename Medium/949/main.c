#include <stdio.h> 
#include <stdlib.h>

int result;

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int valid(int time){
  return (time%100 < 60) && time/100 < 24;
}

int larger(int a, int b){
  return a > b ? a : b;
}

int return_int(int* arr){
  return arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
}

void permutations(int *arr, int start, int end){
  if(start == end){ 
    int time = return_int(arr);
    if (valid(time)) {
        result = larger(result, time);
    }
    return;
  }

  for(int i=start; i<end; i++){
    swap(&arr[start], &arr[i]); 
    permutations(arr, start + 1, end);
    swap(&arr[start], &arr[i]);
  }
}

char* largestTimeFromDigits(int* arr, int arrSize) {

  result = -1;
  permutations(arr, 0, arrSize);

  if (result == -1) return "";

  char* time_str = (char *)malloc(6*sizeof(char));

  sprintf(time_str, "%02d:%02d", result / 100, result % 100);
  
  return time_str;
}
