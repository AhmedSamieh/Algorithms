class Solution {
public:
    int getSum(int a, int b){
        unsigned int Sum = 0;
        unsigned int Carry = 0;
        do
        {
            Sum = a ^ b;
            Carry = (unsigned(a) & unsigned(b)) << 1;
            a = Sum;
            b = Carry;
        } while (b != 0);
        return Sum;
    }
};