//Be attentive with size if infinity!!!
const ll inf = 2e9+3;

//Simple data structure that describes the edge of the graph
struct edge {
    edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
    int from, to;
    int cost;
};

...

int n; //Quantity of vertexes
vector<edge> g; //List of edges
vector<int> d, p;  //Shortest way between s and others and list of vertexes that we visited before ith-vertex.

d.assign(n, 0); //idk why not infinity, it is magic. I think it is why we try set all vertexes as start-vertexes
p.assign(n, -1);

bool any = true;
int last_v; //It is last vertex that we visited in algorithm. If there is negative cycle, this vertex always OR in cycle OR reachable from cycle

//Check ford-bellman algorithm.
//It needs maximum only N - 1 iterations for find answer!
//If it is not, it mean that graph have cycle with negative weight!
for(int it = 0; it < n && any; it++) {
    any = false;
    for(auto &x : g) {
        if(d[x.to] > d[x.from] + x.cost && d[x.to] < inf) {
            d[x.to] = d[x.from] + x.cost;
            p[x.to] = x.from;
            last_v = x.from;
            any = true;
        }
    }
}

if(!any) {
    //There is not negative cycle.
} else {
    //There is negative cycle.

    //Vertex last_v always OR in cycle OR reachable from cycle.
    //But we need to have the vertex which is guaranteed n the cycle.
    //So we going to previous vertex n times. n is global quantity of vertexes so v will be guaranteed in the cycle.
    int v = last_v;
    for(int i = 0; i < n; i++) {
        v = p[v];
    }

    vector<int> cycle; //Vertexes in the cycle
    //So v in the cycle. That is why we going to previous vertex until we reach this vertex again.
    //All intermediate vertexes are in cycle too.
    int saved = v;
    do {
        cycle.push_back(v);
        v = p[v];
    } while(v != saved);

    //But found cycle is reversed. SO we reverse it and make it normal.
    reverse(cycle.begin(), cycle.end());

    ///NOW CYCLE CONTAINS ALL VERTEXES IN NEGATICE CYCLE.
    ///WELL DONE!

}
//Be attentive with size if infinity!!!
const ll inf = 2e9+3;

//Simple data structure that describes the edge of the graph
struct edge {
    edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
    int from, to;
    int cost;
};

...

int n; //Quantity of vertexes
vector<edge> g; //List of edges
vector<int> d, p;  //Shortest way between s and others and list of vertexes that we visited before ith-vertex.

d.assign(n, 0); //idk why not infinity, it is magic. I think it is why we try set all vertexes as start-vertexes
p.assign(n, -1);

bool any = true;
int last_v; //It is last vertex that we visited in algorithm. If there is negative cycle, this vertex always OR in cycle OR reachable from cycle

//Check ford-bellman algorithm.
//It needs maximum only N - 1 iterations for find answer!
//If it is not, it mean that graph have cycle with negative weight!
for(int it = 0; it < n && any; it++) {
    any = false;
    for(auto &x : g) {
        if(d[x.to] > d[x.from] + x.cost && d[x.to] < inf) {
            d[x.to] = d[x.from] + x.cost;
            p[x.to] = x.from;
            last_v = x.from;
            any = true;
        }
    }
}

if(!any) {
    //There is not negative cycle.
} else {
    //There is negative cycle.

    //Vertex last_v always OR in cycle OR reachable from cycle.
    //But we need to have the vertex which is guaranteed n the cycle.
    //So we going to previous vertex n times. n is global quantity of vertexes so v will be guaranteed in the cycle.
    int v = last_v;
    for(int i = 0; i < n; i++) {
        v = p[v];
    }

    vector<int> cycle; //Vertexes in the cycle
    //So v in the cycle. That is why we going to previous vertex until we reach this vertex again.
    //All intermediate vertexes are in cycle too.
    int saved = v;
    do {
        cycle.push_back(v);
        v = p[v];
    } while(v != saved);

    //But found cycle is reversed. SO we reverse it and make it normal.
    reverse(cycle.begin(), cycle.end());

    ///NOW CYCLE CONTAINS ALL VERTEXES IN NEGATICE CYCLE.
    ///WELL DONE!

}
