int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int i = 0, j = numbersSize -1;
    int* result = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    while(i < j)
    {
        if(numbers[i] + numbers[j] == target)
        {
            result[0] = i+1;
            result[1] = j+1;
            break;
        }
        else if((numbers[i] + numbers[j]) < target)
            i++;
        else 
            j--;
    }
    return result;
}