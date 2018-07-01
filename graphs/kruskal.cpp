///Is DSU realization
class Set {
public:
    Set(int n) {
        p.resize(n);
        r.resize(n);
        reset();
    }
    void reset() {
        iota(p.begin(), p.end(), 0);
        fill(r.begin(), r.end(), 1);
    }
    int get(int v) {
        if(p[v] == v) return v;
        return p[v] = get(p[v]);
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x != y) {
            if(r[y] > r[x]) swap(x, y);
            p[y] = p[x];
            r[x] += r[y];
        }
    }
private:
    vector<int> p;
    vector<int> r;
};

int main() {

    ///.first - distance, .second.first - first vertex, .second.second - second vertex
    vector<pair<int, pair<int, int>>> g;
    int n;

    ...

    sort(g.begin(), g.end());
    Set s(5005);

    ///If edge connects two verticles from different sets, then we connect them
    for(int cur = 0; cur < g.size(); cur++) {
        auto k = g[cur];
        if(s.get(k.xx) != s.get(k.yy)) {
            s.unite(k.xx, k.yy);
        }
    }

    return 0;
}
