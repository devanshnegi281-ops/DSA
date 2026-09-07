int longestSubarray(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    int right = 0, left = 0, c = 0, temp = 0;
    while(right < numsSize)
    {
        if(nums[right] == 0)
            temp++;
        while(temp > 1)
        {
            if(nums[left] == 0)
                temp--;
            left++;
        }
        if((right - left + 1) > c)
            c = right - left;
        right++;
    }
    return c;
}