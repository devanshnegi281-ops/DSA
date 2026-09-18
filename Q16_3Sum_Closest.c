int threeSumClosest(int* nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] < nums[i])
            {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++)
    {
        int l = i + 1, r = numsSize - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (abs(target - sum) < abs(target - closest))
                closest = sum;
            if (sum < target)
                l++;
            else if (sum > target)
                r--;
            else
                return sum;
        }
    }
    return closest;
}