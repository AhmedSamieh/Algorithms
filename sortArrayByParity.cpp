class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int back = A.size() - 1;
        int front = 0;
        while (1)
        {
            while (back > front && (A[back] & 1) == 1) --back;
            while (back > front && (A[front] & 1) == 0) ++front;
            if (back > front)
            {
                swap(A[front], A[back]);
            }
            else
            {
                break;
            }
        }
        return A;
    }
};