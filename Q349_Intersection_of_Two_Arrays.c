int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    bool seen[1001] = {false};
    bool added[1001] = {false};
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++)
        seen[nums1[i]] = true;
    for (int i = 0; i < nums2Size; i++)
    {
        if (seen[nums2[i]] && !added[nums2[i]])
        {
            result[(*returnSize)++] = nums2[i];
            added[nums2[i]] = true;
        }
    }
    return result;
}