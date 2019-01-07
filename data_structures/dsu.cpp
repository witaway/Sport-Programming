struct Set {
    vector<int> p
    vector<int> r;

    Set(int n) {
        p.resize(n);
        r.resize(n);
        reset();
    }

    void reset() {
        fill(r.begin(), r.end(), 1);
        iota(p.begin(), p.end(), 0);
    }

    ///I don't know how this magic works.
    int get(int x) {
        if(p[x] == x) return x;
        ///BE ATTENTIVE! get(p[x]) - NOT get(x) !!!
        return p[x] = get(p[x]);
    }

    void unite(int a, int b) {
        a = get(a), b = get(b);
        if(a != b) {
            if(r[b] > r[a]) swap(a, b);
            r[a] += r[b];
            p[b] = p[a];
        }
    }
};
