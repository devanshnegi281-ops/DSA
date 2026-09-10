int majorityElement(int* nums, int numsSize)
{
    int temp = nums[0];
    int c = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (c == 0)
        {
            temp = nums[i];
            c = 1;
        }
        else if (nums[i] == temp)
            c++;
        else
            c--;
    }
    return temp;
}