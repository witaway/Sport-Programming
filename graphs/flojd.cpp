const int inf = INT_MAX / 2;
vector<vector<int>> g;
int n, s, f;

for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
        for(int j = 0; j < g.size(); j++) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
}

cout << g[s][f];
