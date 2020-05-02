/* Given a non negative integer number num.
   For every numbers i in the range 0 ≤ i ≤ num
   calculate the number of 1's in their binary representation and return them as an array.
*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> v(num + 1, 0);
        int step = 0, next_step = 1;

        for (int i = 1; i <= num; ++i) {
            if (i == next_step) {
                v[i] = 1;
                step = next_step;
                next_step <<= 1;
            } else {
                v[i] = 1 + v[i ^ step];
            }
        }

        return v;
    }
};