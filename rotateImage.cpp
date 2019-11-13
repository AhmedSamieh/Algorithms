vector<vector<int>> rotateImage(vector<vector<int>> a) {
    for (int i = 0; i < a.size() / 2; i++)
    {
        for (int j = i ; j < ((a.size() - 1) - i); j++)
        {
            int temp = a[i][j];
            a[i][j] = a[(a.size() - 1) - j][i];
            a[(a.size() - 1) - j][i] = a[(a.size() - 1) - i][(a.size() - 1) - j];
            a[(a.size() - 1) - i][(a.size() - 1) - j] = a[j][(a.size() - 1) - i];
            a[j][(a.size() - 1) - i] = temp;
        }
    }
    return a;
}