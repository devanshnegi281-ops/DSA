char* reverseVowels(char* s)
{
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right)
    {
        while (left < right && !(tolower(s[left])=='a'||tolower(s[left])=='e'||tolower(s[left]) =='i'||tolower(s[left])=='o'||tolower(s[left])=='u'))
            left++;
        while (left < right && !(tolower(s[right])=='a'||tolower(s[right])=='e'||tolower(s[right])=='i'||tolower(s[right])=='o'||tolower(s[right])=='u'))
            right--;
        if (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    return s;
}