int mySqrt(int x) {
    // find last bit
    int i, sqrt = 0;
    for (i = 30; i > 1; --i)
    {
        if (x & (1 << i))
        {
            break;
        }
    }
    i >>= 1;
    do
    {
        sqrt |= (1 << i);
        if (sqrt > 46340 || (sqrt * sqrt) > x)
        {
            sqrt &= ~(1 << i);
        }
        i--;
    } while (i >= 0);
    return sqrt;
}
