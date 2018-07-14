vector<int> lis(vector<int> a) {

    vector<int> dp(a.size(), 1);
    vector<int> p(a.size(), -1);

    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }

    int mx = INT_MIN, pos = -1;
    for(int i = 0; i < dp.size(); i++) {
        if(dp[i] > mx) {
            mx = dp[i];
            pos = i;
        }
    }

    vector<int> ans;
    for(; pos != -1; pos = p[pos]) {
        ans.push_back(a[pos]);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int lis_logn(vector<int> a) {

    vector<int> dp;

    dp.reserve(a.size());
    for(auto &x : a) {
        int j = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if(j == dp.size()) dp.push_back(x);
        else dp[j] = min(dp[j], x);
    }

    return dp.size();
}
