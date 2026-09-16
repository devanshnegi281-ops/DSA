void reverse(int* q, int start, int end)
{
    while(start < end)
    {
        int temp = q[start];
        q[start++] = q[end];
        q[end--] = temp;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    k %= numsSize;
    reverse(nums,0,numsSize - 1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize - 1);
}