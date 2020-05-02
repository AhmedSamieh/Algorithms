class TwoSum
{
    unordered_map<int, int> ds; // number, count
public:
    /** Initialize your data structure here. */
    TwoSum()
    {

    }

    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        ds[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        for (auto &i : ds) {
            int num = value - i.first;

            if (num == i.first) {
                if (i.second > 1) {
                    return true;
                }
            } else {
                if (ds.find(num) != ds.end()) {
                    return true;
                }
            }
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */