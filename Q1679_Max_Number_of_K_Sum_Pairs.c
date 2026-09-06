int maxOperations(int* nums, int numsSize, int k)
{
    int cmp(const void* a, const void* b)
    {
        return (*(int*)a - *(int*)b);
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 0, r = numsSize - 1;
    int c = 0;
    while (l < r)
    {
        int sum = nums[l] + nums[r];
        if(sum < k)
            l++;
        else if(sum > k)
            r--;
        else
        {
            c++;
            l++;
            r--;
        }
    }
    return c;
}