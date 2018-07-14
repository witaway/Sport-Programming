vector<int> lcs(vector<int> a, vector<int> b) {

    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            ///Because dp have 0-barrier and a,b do not. (protection of going abroad)
            int ii = i + 1, jj = j + 1;
            if(a[i] == b[j]) dp[ii][jj] = dp[ii - 1][jj - 1] + 1;
            else dp[ii][jj] = max(dp[ii - 1][jj], dp[ii][jj - 1]);
        }
    }

    vector<int> ans;
    for(int i = a.size(), j = b.size(); i != 0 && j != 0; ) {
        if(a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--, j--;
        } else {
            if(dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
