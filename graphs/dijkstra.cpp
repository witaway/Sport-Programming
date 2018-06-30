int main() {
    const int inf = INT_MAX / 2;
    vector<vector<pair<int, int>>> g;
    set<pair<int, int>> q;
    vector<int> d(n, inf);
    int n, s, f;

    ...

    q.insert({0, s});
    d.assign(n, inf);
    d[s] = 0;

    while(!q.empty()) {
        int l  = (q.begin())->first, v = (q.begin())->second;
        q.erase(q.begin());
        if(l > d[v]) continue;
        for(auto &x : g[v]) {
            int to = x.first, len = x.second;
            if(d[to] > d[v] + len) {
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    cout << (d[f] == inf ? -1 : d[f]);
}
