class Solution
{
public:
    int particalVelocity(vector<int> &A)
    {
        int speed = 0;
        int prev_speed = 0;
        int stable_period = 0;

        for (int = 1; i < A.size(); ++i) {
            speed = A[i] - A[i - 1];

            if (speed == prev_speed) {
                ++stable_period;
            }

            prev_speed = speed;
        }

return (stable_period > 1000000000) stable_period :
               -1;
    }
};
