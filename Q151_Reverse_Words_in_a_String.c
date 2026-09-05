char* reverseWords(char* s)
{
    int len = strlen(s);
    char* result = (char*)malloc(len + 1);
    int k = 0;
    int i = len - 1;
    while (i >= 0)
    {
        while (i >= 0 && isspace(s[i]))
            i--;
        if (i < 0)
            break;
        int j = i;
        while (j >= 0 && !isspace(s[j]))
            j--;
        int start = j + 1;
        int end = i;
        while(start <= end)
            result[k++] = s[start++];
        result[k++] = ' ';
        i = j - 1;
    }
    if (k > 0)
        k--;
    result[k] = '\0';
    return result;
}