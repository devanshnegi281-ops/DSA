int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize <= 2)
        return numsSize;
    int index = 2;
    for(int i = 2; i < numsSize; i++)
    {
        if(nums[index - 2] != nums[i])
            nums[index++] = nums[i];
    }
    return index;
}