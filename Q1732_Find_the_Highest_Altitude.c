int largestAltitude(int* gain, int gainSize)
{
    if(gainSize == 0)
        return 0;
    int c = 0;
    int temp = 0;
    for(int i = 0; i < gainSize; i++)
    {
        temp += gain[i];
        if(c < temp)
            c = temp;
    }
    return c;
}