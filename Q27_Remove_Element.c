int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)
        return 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == val)
        {
            int temp = nums[i];
            nums[i] = nums[numsSize-1];
            nums[numsSize-1] = temp;
            i--;
            numsSize--;
        }
    }
    return numsSize;
}