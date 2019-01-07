int timer;
vector<vector<int>> g(N); ///Adjacency list. N is quantity of vertexes.
vector<int> tin(N), tout(N); ///Time of entry and exit to the vertex in a recursive walk from the vertex root 0.
vector<vector<int>> up(N, vector<int>(31)); ///up[v][i] is an ancestor of v on distance 2^i.

///DFS that prepares graph to find LCA.
void dfs(int v, int pr = -1) {
    tin[v] = ++timer; ///Set entry time.
    up[v][0] = pr; ///Ancestor of v on distance 2^0=1 is the previous vertex=pr.
    ///Here we set ancestors of v on all distances from 2^1 to 2^30.
    for(int i = 1; i <= 30; i++) {
        ///It is kinda difficult to understand.
        ///So ancestor on distance 2^i is the ancestor on distance 2^(i-1) of ancestor on distance 2^(i-1).
        ///That is because 2^(i - 1) * 2^(i - s) == 2^i.
        
        /// (CUR)-............-(a)-.............-(b)
        ///   ↳----(2^(i-1))----↑----(2^(i-1))----↑
        ///   ↳---------------(2^i)---------------↑
        ///If a=up[v][i-1] and b=up[a][i-1], than up[v][i]=b
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    ///And next we just going to neighbour vertexes
    for(auto &to : g[v]) {
        if(to != pr) dfs(to, v);
    }
    tout[v] = ++timer; ///Set exit time.
}

///Check if vertex a upper than vertex b
bool upper(int a, int b) {
    ///tin[a] <= tin[b] - vertex a upper than b if entry time of a less than entry time of b.
    ///tout[a] >= tout[b] - If it is not, than b left of the subtree before a. It is impossible if a and b are in the same subtree.
    return ((tin[a] <= tin[b]) && (tout[a] >= tout[b]));
}

///Function that find lca
int lca(int a, int b) {
    if(upper(a, b)) return a; ///If a upper than b, than LCA(a, b) is a
    if(upper(b, a)) return b; ///If a upper than b, than LCA(a, b) is a
    ///We find the most distant vertex that ancestor of b and not ancestor of a.
    ///The ancestor of this is LCA(a, b)
    for(int i = 30; i >= 0; i--) {
        if(!upper(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

...

timer = 0; ///Preparing timer.
dfs(0, 0); ///Preparing graph

///LCA(a, b) is LCA of a and b now.
