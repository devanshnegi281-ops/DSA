int compress(char* chars, int charsSize)
{
    int r = 0, l = 0;
    while (r < charsSize)
    {
        char ch = chars[r];
        int c = 0;
        while (r < charsSize && chars[r] == ch)
        {
            r++;
            c++;
        }
        chars[l++] = ch;
        if (c > 1)
        {
            char buffer[12];
            sprintf(buffer, "%d", c);
            for (int i = 0; buffer[i] != '\0'; i++)
                chars[l++] = buffer[i];
        }
    }
    return l;
}