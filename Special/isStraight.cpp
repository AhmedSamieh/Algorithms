#include <iostream>
#include <vector>

using namespace std;
enum {
  K,
  Q,
  J,
  Num10,
  Num9,
  Num8,
  Num7,
  Num6,
  Num5,
  Num4,
  Num3,
  Num2,
  A,
  MAX_SIZE
};
bool isStraight(vector<int> &input) {
    if (input.size() <= MAX_SIZE) {
        short found = 0; // // ...A2345678910JQK
        for (int i = 0; i < input.size(); ++i) {
            if (found & (1 << input[i])) {
                return false;
            }
            found |= (1 << input[i]);
        }
        int i = 0;
        while (!(found & 1)) {
            found >>= 1;
            ++i;
        }
        if (i == 0) {
            found &= ~(1 << A);
        }
        if (!(found & (found + 1))) {
            return true;
        }
        return false;
    }
    return false;
}

int main(void) {
    // testing
    // expected output (bool), input (vector<int>)
    vector< pair<bool, vector<int> > > test_cases = {
        make_pair(true , vector<int>({A, Num2, Num3, Num4})),
        make_pair(true , vector<int>({A, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true , vector<int>({Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true , vector<int>({A, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(true , vector<int>({A, K})),
        make_pair(true , vector<int>({Num7, Num8, Num9, Num10, J})),
        make_pair(true , vector<int>({A})),
        make_pair(true , vector<int>({Num9, Num10, J, Q, K})),
        make_pair(true , vector<int>({Num3})),
        make_pair(false, vector<int>({A, Num2, Num3, Num3})),
        make_pair(false, vector<int>({A, Num2, Num4})),
        make_pair(false, vector<int>({A, Num2, K})),
        make_pair(false, vector<int>({Num2, Num3, Num4, Num5, Num7, Num8, Num9, Num10, J, Q, K})),
        make_pair(false, vector<int>({A, Num2, Num4, Num5, Num6, Num7, Num8, Num9, Num10, J, Q, K}))
    };

    for (int i = 0; i < test_cases.size(); ++i) {
        cout << ((test_cases[i].first == isStraight(test_cases[i].second)) ? "PASS" : "FAIL") << endl;
    }
}
