const ll inf = 1e17;
const int N = 1e3 + 7;

int n, m, x, y, w;
ll f[N][N], c[N][N];
vector<int> g[N];
vector<ll> d;

bool bfs() {
    d.assign(n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto to : g[v]) {
            if(d[to] == -1 && f[v][to] < c[v][to]) {
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    return d[n - 1] != -1;
}

ll dfs(int v, ll k) {
    if(!k) return 0;
    if(v == n - 1) return k;
    for(auto to : g[v]) {
        if(d[to] != d[v] + 1) continue;
        ll add = dfs(to, min(k, c[v][to] - f[v][to]));
        if(add != 0) {
            f[v][to] += add;
            f[to][v] -= add;
            return add;
        }
    }
    return 0;
}

///Hi There!
int main(int argc, char **argv) {
	
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back(y);
        c[x][y] = w;
    }

    ll ans = 0;
    while(bfs()) {
        while(ll add = dfs(0, inf)) {
            ans += add;
        }
    }

    cout << ans;

    return EXIT_SUCCESS;
}

