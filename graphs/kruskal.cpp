///Simple data structure that describes the edge of the graph
struct edge {
    edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
    int from, to;
    int cost;
};

///Just comparator
bool comp(edge a, edge b) {
    return a.cost < b.cost;
}

...

int n; ///Quantity of vertexes
vector<edge> g; ///List of edges of graph

Set s(n); ///DSU data structure. Read about it. (data_structures/dsu.cpp)
sort(g.begin(), g.end(), comp);

for(auto &edge : g) {
    ///If edge connects two verticles from different sets, then we connect them
    if(s.get(edge.from) != s.get(edge.to)) {
        s.unite(edge.from, edge.to);
    }
}
