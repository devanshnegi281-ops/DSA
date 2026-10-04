int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int findLHS(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int left = 0, right = 0;
    int maxLen = 0;
    while (right < numsSize)
    {
        if (nums[right] - nums[left] == 1)
        {
            int len = right - left + 1;
            if (len > maxLen)
                maxLen = len;
            right++;
        }
        else if (nums[right] - nums[left] < 1)
            right++;
        else
            left++;
    }
    return maxLen;
}