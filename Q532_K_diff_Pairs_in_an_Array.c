int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int findPairs(int* nums, int numsSize, int k)
{
    if (k < 0 || numsSize < 2)
        return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    int left = 0, right = 1;
    while (left < numsSize && right < numsSize)
    {
        if (left == right || nums[right] - nums[left] < k)
            right++;
        else if (nums[right] - nums[left] > k)
            left++;
        else
        {
            count++;
            left++;
            right++;
            while (left < numsSize && nums[left] == nums[left - 1])
                left++;
        } 
    }
    return count;
}