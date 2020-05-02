#define max(a, b) ((a) > (b) ? (a) : (b))

int longestCommonSubsequence(char *text1, char *text2)
{
    int t1_size = strlen(text1);
    int t2_size = strlen(text2);
    int result;
    int *dp = malloc(sizeof(int) * (t1_size + 1) * (t2_size + 1));

    for (int i = 0; i <= t1_size; i++) {
        for (int j = 0; j <= t2_size; j++) {
            if (i == 0 || j == 0) {
                dp[j * (t1_size + 1) + i] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[j * (t1_size + 1) + i] = dp[(j - 1) * (t1_size + 1) + (i - 1)] + 1;
            } else {
                dp[j * (t1_size + 1) + i] = max(dp[j * (t1_size + 1) + (i - 1)], dp[(j - 1) * (t1_size + 1) + i]);
            }
        }
    }

    result = dp[((t1_size + 1) * (t2_size + 1)) - 1];
    free(dp);
    return result;
}
