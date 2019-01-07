vector<vector<int>> g; //adjacency matrix

//https://ru.stackoverflow.com/questions/642078/
for(int k = 0; k < g.size(); k++) {
    for(int i = 0; i < g.size(); i++) {
        for(int j = 0; j < g.size(); j++) {
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
    }
}

//Now g[i][j] is the shortest way between vertex №i and vertex №j
