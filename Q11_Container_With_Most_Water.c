int maxArea(int* height, int heightSize)
{
    int *left = &height[0] , *right = &height[heightSize - 1];
    long long int area = 0,temp = 0;
    while(left > right)
    {
        if(*left > *right)
        {
            temp = *right * (right - left);
            right--;
        }
        else
        {
            temp = *left * (right - left);
            left++;
        }
        if(temp > area)
        area = temp;
    }
    return area;
}