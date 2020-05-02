class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> ret;
        ret.reserve(A.size());
        int pos_ref = upper_bound(A.begin(), A.end(), -1) - A.begin();
        int pos_i = pos_ref, neg_i = pos_ref - 1;

        while (pos_i < A.size() && neg_i >= 0) {
            if ((-A[neg_i]) < A[pos_i]) {
                ret.push_back(A[neg_i] * A[neg_i]);
                --neg_i;
            } else {
                ret.push_back(A[pos_i] * A[pos_i]);
                ++pos_i;
            }
        }

        while (pos_i < A.size()) {
            ret.push_back(A[pos_i] * A[pos_i]);
            ++pos_i;
        }

        while (neg_i >= 0) {
            ret.push_back(A[neg_i] * A[neg_i]);
            --neg_i;
        }

        return ret;
    }
};