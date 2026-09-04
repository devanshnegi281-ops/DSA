char* gcdOfStrings(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* concat1 = (char*)malloc(len1 + len2 + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    char* concat2 = (char*)malloc(len1 + len2 + 1);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    if (strcmp(concat1, concat2) != 0)
    {
        free(concat1);
        free(concat2);
        return "";
    }
    free(concat1);
    free(concat2);
    while (len2 != 0)
    {
        int temp = len2;
        len2 = len1 % len2;
        len1 = temp;
    }
    int gcdLen = len1;
    char* result = (char*)malloc(gcdLen + 1);
    strncpy(result, str1, gcdLen);
    result[gcdLen] = '\0';
    return result;
}
