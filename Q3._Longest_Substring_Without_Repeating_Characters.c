#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int a[256];
    for(int i = 0; i < 256; i++)
        a[i] = -1;
    int maxLen = 0, start = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        if(a[(unsigned char)s[i]] >= start)
            start = a[(unsigned char)s[i]] + 1;
        a[(unsigned char)s[i]] = i;
        int len = i - start + 1;
        if(len > maxLen) maxLen = len;
    }
    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
