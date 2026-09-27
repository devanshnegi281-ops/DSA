int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int *result = (int *)malloc(sizeof(int)*numsSize);
    int c = 0,k = 0;
    for(int i = 0; i < numsSize; i++)
    {
        c = 0;
        for(int j = 0; j < numsSize; j++)
        {
            if(nums[i] == nums[j])
                c++;
        }
        if(c == 1)
            result[k++] = nums[i];
        if(k == 2)
            break;
    }
    *returnSize = 2;
    return result;
}