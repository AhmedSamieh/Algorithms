#include <iostream>

using namespace std;

bool hasCapital(const char *str)
{
    if (NULL != str) {
        while (*str) {
            if (*str >= 'A' && *str <= 'Z') {
                return true;
            }

            ++str;
        }
    }

    return false;
}

int main()
{
    cout << (!hasCapital("abcdef") ? "PASS" : "FAIL") << endl;
    cout << (hasCapital("abcDef") ? "PASS" : "FAIL") << endl;
    return 0;
}
