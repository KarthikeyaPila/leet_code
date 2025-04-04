int candy(int* arr, int size){

    int candy[size];
    for(int i=0; i<size; i++){
        candy[i] = 1;
    }

    for(int i=1; i < size; i++){
        if(arr[i] > arr[i - 1]){
            candy[i] = candy[i - 1] + 1;
        }
    }

    for(int i=size-2; i >= 0; i--){
        if(arr[i] > arr[i + 1] && candy[i] <= candy[i + 1]){
            candy[i] = candy[i + 1] + 1;
        }
    }

    int total = 0;
    for(int i = 0; i < size; i++){
        total += candy[i];
    }

    return total;
}