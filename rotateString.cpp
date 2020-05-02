class Solution
{
public:
    bool rotateString(string A, string B)
    {
        bool thesame = true;

        if (A.size() != B.size()) {
            thesame = false;
        } else {
            for (int i = 0; i < A.size(); i++) {
                thesame = true;

                for (int j = 0; j < A.size(); j++) {
                    if (A.at(j) != B.at((i + j) % A.size())) {
                        thesame = false;
                        break;
                    }
                }

                if (thesame) {
                    break;
                }
            }
        }

        return thesame;
    }
};