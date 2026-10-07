int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int maximumProduct(int* nums, int numsSize)
{
    if(numsSize < 3)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    int sum1 = nums[0]*nums[1]*nums[numsSize-1];
    int sum2 = nums[numsSize-1]*nums[numsSize-2]*nums[numsSize-3];
    if(sum1 > sum2)
        return sum1;
    else 
        return sum2;
}