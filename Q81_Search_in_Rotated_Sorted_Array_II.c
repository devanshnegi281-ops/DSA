bool search(int* nums, int numsSize, int target)
{
    int i;
    for(i = 0; i < numsSize-1; i++)
    {
        if(nums[i] == target)
            return true;
        else if(nums[i] < target && nums[i] > nums[i+1])
            return false;
    }
    if(target == nums[i])
        return true;
    else
        return false;
}