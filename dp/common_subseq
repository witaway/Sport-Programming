vector<int> a, b;
vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
vector<vector<pair<int, int>>> p(a.size() + 1, vector<pair<int, int>>(b.size() + 1, {-1, -1}));

for(int i = 0; i < a.size(); i++) {
    for(int j = 0; j < b.size(); j++) {
        ///Because dp have 0-barrier and a,b are not.
        int ii = i + 1, jj = j + 1;
        if(a[i] == b[j]) {
            dp[ii][jj] = dp[ii - 1][jj - 1] + 1;
            p[ii][jj] = {ii - 1, jj - 1};
        }
        else {
            ///Read as dp[ii][jj] = max(dp[ii - 1][jj], dp[ii][jj - 1]);
            if(dp[ii - 1][jj] > dp[ii][jj - 1]) {
                dp[ii][jj] = dp[ii - 1][jj];
                p[ii][jj] = p[ii - 1][jj];
            } else {
                dp[ii][jj] = dp[ii][jj - 1];
                p[ii][jj] = p[ii][jj - 1];
            }
        }
    }
}

///Getting sequence
vector<int> ans;
for(pair<int, int> pos = p[a.size()][b.size()]; pos != {-1, -1}; pos = p[pos.ff][pos.ss]) {
    ans.push_back(a[pos.ff]);
}
reverse(ans.begin(), ans.end());

cout << dp[a.size()][b.size()] << endl;
for(auto &x : ans) cout << x << " ";
