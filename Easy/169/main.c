//this is known as moors majority algo.

int majorityElement(int* nums, int numsSize) {
	int freq = 0; 
    int ans = 0;
	
	for(int i = 0; i < numsSize; i++){
		if(freq == 0){
			ans = nums[i];
		}

		if(ans == nums[i]){
			freq++;
		}else{
			freq--;
		}
	}

	return ans;
}


// [2,2,1,1,1,2,2]
// f = 1, a = 2
// [2,2,1,1,1,2,2]
// f = 2, a = 2
// [2,2,1,1,1,2,2]
// f = 1, a = 2
// [2,2,1,1,1,2,2]
// f = 1, a = 1
// [2,2,1,1,1,2,2]
// f = 2, a = 1
// [2,2,1,1,1,2,2]
// f = 1, a = 2
// [2,2,1,1,1,2,2]
// f = 2, a = 2

// return a ==> return 2.


