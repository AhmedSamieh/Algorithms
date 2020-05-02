class Solution
{
public:
    string findContestMatch(int n)
    {
        list<string> q;

        for (int i = 1, j = n; i < j; ++i, --j) {
            q.push_back("(" + to_string(i) + "," + to_string(j) + ")");
        }

        list<string> *l1 = &q;
        list<string> r;
        list<string> *l2 = &r;

        while (l1->size() > 1) {
            while (l1->size() > 1) {
                l2->push_back("(" + l1->front() + "," + l1->back() + ")");
                l1->pop_front();
                l1->pop_back();
            }

            if (l1->size() != 0) {
                l2->push_back(l1->front());
                l1->pop_front();
            }

            swap(l1, l2);
        }

        return l1->front();
    }
};
