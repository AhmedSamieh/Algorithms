class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> char_pos; // char, pos
        for (int i = 0; i < keyboard.size(); ++i)
        {
            char_pos.emplace(keyboard[i], i);
        }
        int distance = 0;
        int prev_pos = 0;
        for (char c : word)
        {
            int current_pos = char_pos[c];
            distance += abs(current_pos - prev_pos);
            prev_pos = current_pos;
        }
        return distance;
    }
};