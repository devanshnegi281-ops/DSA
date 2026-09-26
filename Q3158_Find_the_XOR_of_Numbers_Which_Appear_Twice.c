int duplicateNumbersXOR(int* nums, int numsSize)
{
    int arr[51] = {0};
    int result = 0;
    for(int i = 0; i < numsSize; i++)
        arr[nums[i]]++;
    for(int i = 1; i < 51; i++)
    {
        if(arr[i] == 2)
            result ^= i;
    }
    return result;
}