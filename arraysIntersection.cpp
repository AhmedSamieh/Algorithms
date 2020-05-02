class Solution
{
public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
    {
        vector<int> ret;

        for (int i = 0, j = 0, k = 0; i < arr1.size() && j < arr2.size() && k < arr3.size();) {
            if (arr1[i] == arr2[j] && arr1[i] == arr3[k]) {
                ret.push_back(arr1[i]);
                ++i, ++j, ++k;
            } else {
                int new_i = i, new_j = j, new_k = k;

                if (arr1[i] > arr2[j] || arr2[j] < arr3[k]) {
                    ++new_j;
                }

                if (arr1[i] < arr2[j] || arr1[i] < arr3[k]) {
                    ++new_i;
                }

                if (arr1[i] > arr3[k] || arr2[j] > arr3[k]) {
                    ++new_k;
                }

                i = new_i;
                j = new_j;
                k = new_k;
            }
        }

        return ret;
    }
};