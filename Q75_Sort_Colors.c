void sortColors(int* nums, int numsSize)
{
    for(int i = 0; i < numsSize-1; i++)
    {
        int flag = 0;
        for(int j = 0; j < numsSize-1-i;j++)
        {
            if(nums[j] > nums[j+1])
            {
                flag = 1;
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
        }
        if(flag == 0)
            return;
    }
    return;
}