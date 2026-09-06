int myAtoi(char* s)
{
    if(s == NULL)
        return 0;
    int result = 0, sign = 1, i = 0;
    while(s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\r' || s[i] == '\v' || s[i] == '\f')
        i++;
    if(s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if(s[i] == '+')
    {
        sign = 1;
        i++;
    }
    while(s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + digit;
        i++;
    }
    return result * sign;
}