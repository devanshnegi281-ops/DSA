double myPow(double x, int n)
{
    if (n == 0)
        return 1.0;
    long long exp = n;
    long double base = x;
    if (exp < 0)
    {
        base = 1.0L / base;
        exp = -exp;
    }
    long double result = 1.0L;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result *= base;
        base *= base;
        exp /= 2;
    }
    return (double)result;
}