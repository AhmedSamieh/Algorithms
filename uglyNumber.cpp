class Solution {
public:
    bool isUgly(int num) {
        if (0 == num) {
            return false;
        }
        if (num % 5 == 0) {
            return isUgly(num / 5);
        }
        if (num % 3 == 0) {
            return isUgly(num / 3);
        }
        if (num % 2 == 0) {
            return isUgly(num / 2);
        }
        if (1 == num) {
            return true;
        }
        return false;
    }
};
