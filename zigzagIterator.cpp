static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}
();
class ZigzagIterator
{
    vector<int> v;
    size_t      index_next;
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) : index_next(0)
    {
        v.reserve(v1.size() + v2.size());
        int i = 0;

        while (i < v1.size() && i < v2.size()) {
            v.push_back(v1[i]);
            v.push_back(v2[i++]);
        }

        while (i < v1.size()) {
            v.push_back(v1[i++]);
        }

        while (i < v2.size()) {
            v.push_back(v2[i++]);
        }
    }

    int next()
    {
        if (!hasNext()) {
            return 0;
        }

        return v[index_next++];
    }

    bool hasNext()
    {
        return index_next < v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */