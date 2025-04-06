int* colorTheArray(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    *returnSize = queriesSize;
    int *colors = (int*)calloc(n, sizeof(int));   
    int *result = (int *)malloc(queriesSize*sizeof(int));
    int count = 0;
 

    for(int i=0; i<queriesSize; i++){
        
        if(colors[queries[i][0]] != 0){
            if(queries[i][0] > 0 && colors[queries[i][0]] == colors[queries[i][0]-1]){
                count--;
            }
            if(queries[i][0] < n-1 && colors[queries[i][0]] == colors[queries[i][0]+1]){
                count--;
            }
        }
        
        colors[queries[i][0]] = queries[i][1];

        if(queries[i][1] != 0){
            if(queries[i][0] > 0 && colors[queries[i][0]] == colors[queries[i][0]-1]){
                count++;
            }
            if(queries[i][0] < n-1 && colors[queries[i][0]] == colors[queries[i][0]+1]){
                count++;
            }
        }
        result[i] = count;
    }

    return result;
}
