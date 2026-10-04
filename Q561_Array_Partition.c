int cmp(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    qsort(nums,numsSize,sizeof(int),cmp);
    if(numsSize == 2)
        return nums[0];
    int result = 0;
    for(int i = 0; i < numsSize; i += 2)
        result += nums[i];
    return result;
}