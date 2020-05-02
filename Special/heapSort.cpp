#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> v {7, 2, 4, 3, 8, 21, 6, 17, 1, 5, 9};
    make_heap(v.begin(), v.end()); // O(n)
    sort_heap(v.begin(), v.end()); // O(n log n)

    for (auto &i : v) {
        cout << i << endl;
    }
}
