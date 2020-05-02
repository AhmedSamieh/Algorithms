class Solution
{
    vector<string> letterCombinationsHelper(string &digits, size_t i)
    {
        vector<string> sol;

        if (i == digits.size()) {
            sol.emplace_back("");
        } else {
            const string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            auto sub_sol = letterCombinationsHelper(digits, i + 1);

            for (auto &s : sub_sol) {
                size_t index = digits[i] - '0';

                for (auto &c : letters[index]) {
                    sol.emplace_back(c + s);
                }
            }
        }

        return sol;
    }
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() > 0) {
            return letterCombinationsHelper(digits, 0);
        } else {
            return vector<string>();
        }
    }
};