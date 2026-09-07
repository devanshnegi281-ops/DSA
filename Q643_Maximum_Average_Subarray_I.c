double findMaxAverage(int* nums, int numsSize, int k)
{
    long sum = 0.0;
    for(int i = 0; i < k; i++)
        sum += nums[i];
    long msum = sum;
    for(int i = k; i < numsSize; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        if(sum > msum)
            msum = sum;
    }
    return (double)msum / k;
}