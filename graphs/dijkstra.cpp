const long long inf = 2e9+3;

int s; //start vertex
vector<vector<pair<int, int> > > g; //adjacency list where .first is cost and .second is to-vertex

//Sorted ascending queue of pair<int, int> where .first is cost and .second is to-vertex
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > q;
//Array of costs of vertexes. If vertex's cost is infinite that we cant to reach that vertex.
vector<int> d(n, inf);
d[s] = 0;
q.push({0, s});

while(!q.empty()) {
    int curV = q.top().ss, curW = q.top().ff;
    q.pop();
    //If curW is not optimal and we now have less d[curV], we continue
    if(curW > d[curV]) continue;
    for(auto &to : g[curV]) {
        int toV = to.ss, toW = to.ff;
        if(d[toV] > d[curV] + toW) {
            d[toV] = d[curV] + toW;
            q.push({d[toV], toV});
        }
    }
}

cout << (d[f] == inf ? -1 : d[f]);
