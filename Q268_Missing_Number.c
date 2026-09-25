int missingNumber(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    int result = (numsSize*(numsSize + 1))/2;
    for(int i = 0; i < numsSize; i++)
        result -= nums[i];
    return result;
}