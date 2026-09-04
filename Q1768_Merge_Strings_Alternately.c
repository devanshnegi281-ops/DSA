char * mergeAlternately(char * word1, char * word2){
    char *s = (char*)malloc(201*sizeof(char));
    int i = 0, j = 0, k = 0;
    while(word1[i]!='\0' || word2[j]!='\0')
    {
        if(word1[i]!='\0')
            s[k++] = word1[i++];
        if(word2[j]!='\0')
            s[k++] = word2[j++];
    }
    s[k] = '\0';
    return s;
}