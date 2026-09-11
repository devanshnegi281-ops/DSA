int romanToInt(char* s)
{
    int result = 0;
    int getValue(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default : 
                return 0;
        }
    } 
    for(int i=0 ; i<strlen(s) ; i++)
    {
        if(getValue(s[i])< getValue(s[i+1]))
            result -= getValue(s[i]);
        else
            result += getValue(s[i]);
    }
    return result ;
}