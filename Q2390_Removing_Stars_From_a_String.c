char* removeStars(char* s)
{
    int top = -1;
    char *result = (char*)malloc(strlen(s) + 1);
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] != '*')
            result[++top] = s[i];
        else if(top >= 0)
            top--;
    }
    result[++top] = '\0';
    return result;
}