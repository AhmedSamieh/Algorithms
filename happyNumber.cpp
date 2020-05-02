class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> visited;

        do {
            unsigned long number = 0;

            if (visited.find(n) == visited.end()) {
                visited.insert(n);
            } else {
                return false;
            }

            while (n) {
                int digit = n % 10;
                n /= 10;
                number += (digit * digit);
            }

            n = number;
        } while (n != 1);

        return true;
    }
};
