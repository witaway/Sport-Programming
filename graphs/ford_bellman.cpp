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

int n, s; //Quantity of vertexes and number of start vertex
vector<edge> g; //List of edges
vector<int> d(n, inf); //Shortest way between s and others

d[s] = 0; //We always can reach vertex s from vertex s.

//We continue only if we relax at least one edge.
//And we always do at least one iteration.

//AND FORD-BELLMAN algorithm needs maximum only N - 1 iterations for find answer! 
//If it is not, it mean that graph have cycle with negative weigth! BE ATTENTIVE! 
bool any;
do {
    any = false;
    for(auto &x : g) {
        //We relax edge only if we can reach from-vertex!
        if(d[x.to] > d[x.from] + x.cost && d[x.from] < inf) {
            d[x.to] = d[x.from] + x.cost;
            //We relaxed at least the one edge and we can continue
            any = true;
        }
    }
} while(any);

//Now d[n] is the length of the shortest way between s and n.
//If d[n] == inf than we cant reach vertex number n
