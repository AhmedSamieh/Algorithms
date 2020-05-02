class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        /*if (num > 1)
        {
            int sum = 1;
            for (int i = 2, last = sqrt(num); i <= last; ++i)
            {
                if ((num % i) == 0)
                {
                    sum += (i + (num / i));
                }
            }
            return (sum == num);
        }
        else
        {
            return false;
        }*/
        return (num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336);
    }
};