#include <iostream>
using namespace std;

// Input string is all lower case [a-z] characters only.
bool HasDuplicates(const char *input)
{
    uint32_t visited = 0;

    if (NULL != input) {
        while ('\0' != *input) {
            uint32_t flag = 1 << (*input++ - 'a');

            if (visited & flag) {
                return true;
            }

            visited |= flag;
        }
    }

    return false;
}

int main()
{
    cout << (!HasDuplicates("abcdef") ? "PASS" : "FAIL") << endl;
    cout << (HasDuplicates("abcdefnhtfzr") ? "PASS" : "FAIL") << endl;
    return 0;
}

/*bool HasDuplicates(const char* input) {
  bool visited[1 + 'z' - 'a'] = {false};
  if (NULL != input) {
    while ('\0' != *input) {
      auto index = static_cast<size_t>(*input++ - 'a');
      if (visited[index]) {
        return true;
      }
      visited[index] = true;
    }
  }
  return false;
}*/
/*bool HasDuplicates(const char* input) {
  unordered_set<char> visited;
  if (NULL != input) {
    while ('\0' != *input) {
      if (visited.find(*input) != visited.end()) {
          return true;
      }
      visited.insert(*input++);
    }
  }
  return false;
}*/

