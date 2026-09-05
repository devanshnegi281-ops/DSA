bool increasingTriplet(int* nums, int numsSize) {
    int s = INT_MAX;
    int s1 = INT_MAX;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] <= s)
            s = nums[i];
        else if(nums[i] <= s1)
            s1 = nums[i];
        else
            return true;
    }
    return false;
}