int reverseDegree(char* s)
{
    int result = 0;
    for(int i = 0; i < strlen(s); i++)
        result += (i+1)*('z'-s[i]+1);
    return result;
}