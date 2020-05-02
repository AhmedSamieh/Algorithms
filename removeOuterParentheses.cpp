class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string s;
        int step = 0;

        for (auto c : S) {
            if (c == '(') {
                if (++step == 1) {
                    continue;
                }
            } else if (c == ')') {
                if (step-- == 1) {
                    continue;
                }
            }

            s.push_back(c);
        }

        return s;
    }
};