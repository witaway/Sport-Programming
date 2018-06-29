struct edge {
    int v, u, c;
    edge(int v, int u, int c) {
        this->v = v;
        this->u = u;
        this->c = c;
    }
};

...

const int inf = INT_MAX / 2;
vector<edge> g;
vector<int> d;
int n, m;

d.assign(n, inf);
d[0] = 0;

bool any = true;
while(any) {
    any = false;
    for(auto &x : g) {
        if(d[x.u] > d[x.v] + x.c && d[x.v] < inf) {
            d[x.u] = d[x.v] + x.c;
            any = true;
        }
    }
}

