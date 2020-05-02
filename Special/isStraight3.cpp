#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum {
    A,
    Num2,
    Num3,
    Num4,
    Num5,
    Num6,
    Num7,
    Num8,
    Num9,
    Num10,
    J,
    Q,
    K
};

bool isStraight(vector<int> &input)
{
    sort(input.begin(), input.end());
    int i = 0;

    while (++i < input.size() && input[i] == (input[i - 1] + 1));

    if (i == input.size()) {
        return true;
    }

    int j = input.size() - 1;

    if (i > 1 || input[0] != A || input[j] != K) {
        return false;
    }

    while (--j > 0 && input[j] == (input[j + 1] - 1));

    return j == 0;
}

int main(void)
{
    // testing
    // expected output (bool), input (vector<int>)
    vector< pair<bool, vector<int> > > test_cases = {
        make_pair(true, vector<int>({A, Num2, Num3, Num4})),
        make_pair(true, vector<int>({A, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true, vector<int>({Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true, vector<int>({A, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true, vector<int>({A, K})),
        make_pair(true, vector<int>({Num7, Num8, Num9, Num10, J})),
        make_pair(true, vector<int>({A})),
        make_pair(true, vector<int>({Num9, Num10, J, Q, K})),
        make_pair(true, vector<int>({Num3})),
        make_pair(false, vector<int>({A, Num2, Num3, Num3})),
        make_pair(false, vector<int>({A, Num2, Num4})),
        make_pair(false, vector<int>({A, Num2, K})),
        make_pair(false, vector<int>({Num2, Num3, Num4, Num5, Num7, Num8, Num9, J, Q, K})),
        make_pair(false, vector<int>({A, Num2, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K}))
    };

    for (int i = 0; i < test_cases.size(); ++i) {
        cout << ((test_cases[i].first == isStraight(test_cases[i].second)) ? "PASS" : "FAIL") << endl;
    }
}
