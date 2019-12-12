/*
n = 3
"()" <-1
"(())" <-2
"()()" <-2
"(())" <-2 dup
"()()" <-2 dup
"((()))" <-3 <-sol
"()(())" <-3 <-sol
"(()())" <-3 <-sol
"((()))" <-3 dup
"(()())" <-3 dup
"(())()" <-3 <- sol
"(()())" <-3 dup
"()()()" <-3 <- sol
"(())()" <-3 dup
"()()()" <-3 dup
"()(())" <-3 dup
"()()()" <-3 dup
*/
class Solution {
    unordered_set<string> generateParenthesisHelper(int n) {
        unordered_set<string> sol;
        if (n == 1) {
            sol.emplace("()");
        }
        else {
            auto n_minus_1_sol = generateParenthesis(n - 1);
            for (auto &s : n_minus_1_sol) {
                sol.emplace("(" + s + ")");
                for (int i = 0; i < s.size(); ++i) {
                    string new_s(s);
                    new_s.insert(i, "()");
                    sol.emplace(new_s);
                }
            }
        }
        return sol;
    }
public:
    vector<string> generateParenthesis(int n) {
        auto n_sol = generateParenthesisHelper(n);
        return vector(n_sol.begin(), n_sol.end());
    }
};