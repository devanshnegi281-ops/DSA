int cmp(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int findMinDifference(char** timePoints, int timePointsSize)
{
    if (timePointsSize > 1440)
        return 0;
    int* minutes = (int*)malloc(sizeof(int) * timePointsSize);
    for (int i = 0; i < timePointsSize; i++)
    {
        int hour = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
        int min  = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
        minutes[i] = hour * 60 + min;
    }
    qsort(minutes, timePointsSize, sizeof(int), cmp);
    int minDiff = 1440;
    for (int i = 1; i < timePointsSize; i++)
    {
        int diff = minutes[i] - minutes[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    int wrapDiff = 1440 - minutes[timePointsSize - 1] + minutes[0];
    if (wrapDiff < minDiff)
        minDiff = wrapDiff;
    free(minutes);
    return minDiff;
}