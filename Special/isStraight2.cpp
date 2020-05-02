#include <iostream>
#include <vector>

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
    short found = 0;

    for (auto &i : input) {
        if (found & (1 << i)) {
            return false;
        }

        found |= (1 << i);
    }

    if (found) {
        if (found & 1) { // A
            if ((found & 2) == 0) { // not Num2
                found = (~(found & ~(1))) & 0x1FFF;
            }
        } else {
            while ((found & 1) == 0) {
                found >>= 1;
            }
        }

        return !(found & (found + 1));
    }

    return false;
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