/*
// 84 ms solution
class Solution {
    pair<size_t , size_t> get_second_word(string &log) {
        pair<size_t , size_t > pos; // first = start, second = end
        pos.first = log.find(' ') + 1;
        pos.second = log.find(' ', pos.first + 1);
        if (pos.second == string::npos) {
            pos.second = log.size() + 1;
        }
        return pos;
    }
    bool isDigit(string &log, pair<size_t , size_t>& pos) {
        for (size_t i = pos.first; i < pos.second; ++i) {
            if (log[i] > '9') {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ret;
        map<string, vector<size_t>> letters_index;
        vector<size_t> digit_index;
        ret.reserve(logs.size());
        for (size_t i = 0; i < logs.size(); ++i) {
            auto pos = get_second_word(logs[i]);
            if (isDigit(logs[i], pos)) {
                digit_index.push_back(i);
            }
            else {
                letters_index[logs[i].c_str() + pos.first].push_back(i);
            }
        }
        for (auto &v : letters_index) {
            sort(v.second.begin(), v.second.end(), [logs](size_t &i, size_t &j) {
                string id1 = logs[i].substr(0, logs[i].find(' '));
                string id2 = logs[j].substr(0, logs[j].find(' '));
                return id1 < id2;
            });
            for (auto &i : v.second) {
                ret.emplace_back(logs[i]);
            }
        }
        for (auto &i : digit_index) {
            ret.emplace_back(logs[i]);
        }
        return ret;
    }
};*/
// 4 ms solution
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ret(logs.size());
        map<string, size_t> letters_index;
        size_t next_letters_pos = 0;
        size_t next_digit_pos = logs.size() - 1;
        for (int i = logs.size() - 1; i >= 0; --i) {
            auto pos = logs[i].find(' ') + 1;
            if (isdigit(logs[i][pos])) {
                ret[next_digit_pos--] = logs[i];
            }
            else {
                letters_index[string(logs[i].c_str() + pos) + logs[i].substr(0, pos - 1)] = i;
            }
        }
        for (auto &i : letters_index) {
            ret[next_letters_pos++] = logs[i.second];
        }
        return ret;
    }
};
