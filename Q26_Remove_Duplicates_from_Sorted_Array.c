int removeDuplicates(int* nums, int numsSize)
{
    int index = 1;
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] != nums[index-1])
            nums[index++] = nums[i];
    }
    return index;
}