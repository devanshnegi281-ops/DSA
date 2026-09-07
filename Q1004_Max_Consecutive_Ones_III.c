int longestOnes(int* nums, int numsSize, int k)
{
    int right = 0, left = 0, c = 0,temp = 0;
    while(right < numsSize)
    {
        if(nums[right] == 0)
            temp++;
        while(temp > k)
        {
            if(nums[left] == 0)
                temp--;
            left++;
        }
        if((right - left + 1) > c)
            c = right - left + 1;
        right++;
    }
    return c;
}