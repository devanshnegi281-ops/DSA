int singleNumber(int* nums, int numsSize)
{
    int c;
    for(int i = 0; i < numsSize; i++)
    {
        c = 0;
        for(int j = 0; j < numsSize; j++)
        {
            if(nums[i] == nums[j])
                c++;
        }
        if(c == 1)
            return nums[i];
    }
    return 0;
}