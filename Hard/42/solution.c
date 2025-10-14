int trap(int* arr, int heightSize) {
    int store_water = 0; 
    
    int r = heightSize-1, rmax = arr[r];
    int l = 0, lmax = arr[l]; 

    while(l<r) {
        if(lmax >= rmax) {
            r--; 
            if(arr[r] > rmax) {
                rmax = arr[r];
            }
            store_water += rmax - arr[r];
        } else {
            l++; 
            if(arr[l] > lmax) {
                lmax = arr[l];
            }
            store_water += lmax - arr[l];
        }
    }

    return store_water; 
}