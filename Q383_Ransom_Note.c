bool canConstruct(char* ransomNote, char* magazine)
{
    int a[26] = {0};
    if(strlen(ransomNote) > strlen(magazine))
        return false;
    for(int i = 0; i < strlen(ransomNote); i++)
        a[ransomNote[i] - 'a'] += 1;
    for(int j = 0; j < strlen(magazine); j++)
        a[magazine[j] - 'a'] -= 1;
    for(int i = 0; i < 26; i++)
    {    
        if(a[i] > 0)
            return false;
    }
    return true;
}