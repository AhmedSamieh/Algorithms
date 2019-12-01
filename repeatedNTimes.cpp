class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (auto &i : A)
        {
            if (s.find(i) == s.end())
            {
                s.insert(i);
            }
            else
            {
                return i;
            }
        }
        /*sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] == A[i - 1])
            {
                return A[i];
            }
        }*/
        return 0;
    }
};