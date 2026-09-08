/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int *result = (int*)malloc(asteroidsSize * sizeof(int));
    int top = 0;
    result[top] = asteroids[0];
    for(int i = 1; i < asteroidsSize; i++)
    {
        int curr = asteroids[i];
        int alive = 1;
        while (alive && curr < 0 && top >= 0 && result[top] > 0)
        {
            if (result[top] < -curr)
                top--;
            else if (result[top] == -curr)
            {
                top--;
                alive = 0;
            }
            else
                alive = 0;
        }
        if (alive)
            result[++top] = curr;
    }
    *returnSize = top + 1;
    return result;
}