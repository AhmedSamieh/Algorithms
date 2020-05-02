class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        const string code_map[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;

        for (auto const &word : words) {
            string code;

            for (auto c : word) {
                code += code_map[int(c) - int('a')];
            }

            s.insert(code);
        }

        return s.size();
    }
};