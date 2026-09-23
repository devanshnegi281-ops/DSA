int digitSquareSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow = n, fast = digitSquareSum(n);
    while (fast != 1 && slow != fast)
    {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
    }
    return fast == 1;
}