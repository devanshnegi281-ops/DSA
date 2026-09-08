int pivotIndex(int* nums, int numsSize)
{
    if(numsSize == 0)
        return -1;
    long suml = 0,total = 0;
    for(int i = 0; i < numsSize; i++)
        total += nums[i];
    for(int i = 0; i < numsSize; i++)
    {
        if(suml == total - suml - nums[i])
            return i;
        suml += nums[i];
    }
    return -1;
}