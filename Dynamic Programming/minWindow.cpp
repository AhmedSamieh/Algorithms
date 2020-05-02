#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// "abcdebdde", "bde"
// "bdebdde"
// "1345678"
class Solution
{
public:
    string minWindow(string S, string T)
    {
        if (S.size() > 0 && T.size() > 0) {
            unordered_set<char> sT(T.begin(), T.end());
            string pS;
            vector<int> piS;

            for (int i = 0; i < S.size(); ++i) {
                if (sT.find(S[i]) != sT.end()) {
                    pS.push_back(S[i]);
                    piS.push_back(i);
                }
            }

            int best = S.size() + 1;
            int start;

            for (int x = pS.find(T[0], 0); x != string::npos && x <= (pS.size() - T.size()); x = pS.find(T[0], x + 1)) {
                int i, j;

                for (i = 0, j = x; i < T.size() && j < pS.size(); ++j) {
                    if (T[i] == pS[j]) {
                        ++i;
                    }
                }

                if (i == T.size()) {
                    // got it
                    int length = 1 + piS[j - 1] - piS[x];

                    if (best > length) { // get the best
                        best = length;
                        start = piS[x];
                    }
                }
            }

            if (best <= S.size()) {
                return S.substr(start, best);
            }
        }

        return "";
    }
};
int main(int argc, char **argv)
{
    Solution sol;
    string S = "abcdebdde", T = "bde";
    cout << sol.minWindow(S, T) << endl;
}
