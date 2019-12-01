bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
    string str1 = "", str2 = "", str3 = "";
    int val1, val2, val3;
    unordered_map<char, char> solution_map;
    for (int i = 0; i < solution.size(); i++)
    {
        solution_map.insert(make_pair(solution[i][0], solution[i][1]));
    }
    for (int i = 0; i < crypt[0].size(); i++)
    {
        str1 += solution_map[crypt[0][i]];
    }
    for (int i = 0; i < crypt[1].size(); i++)
    {
        str2 += solution_map[crypt[1][i]];
    }
    for (int i = 0; i < crypt[2].size(); i++)
    {
        str3 += solution_map[crypt[2][i]];
    }
    val1 = atoi(str1.c_str());
    val2 = atoi(str2.c_str());
    val3 = atoi(str3.c_str());
    //printf("%s + %s = %s\n", str1.c_str(), str2.c_str(), str3.c_str());
    return (((val1 + val2) == val3) &&
            (str1[0] != '0' || str1.size() == 1) &&
            (str2[0] != '0' || str2.size() == 1) &&
            (str3[0] != '0' || str3.size() == 1));
}