template<typename T>
struct segtree {
    int n;
    vector<T> t;

    segtree(int sz) {
        this->n = 1;
        while(this->n < sz) this->n <<= 1;
        t.assign(this->n + this->n, {INT_MIN, -1});
    }

    T combine(T a, T b) {
        return max(a, b);
    }

    void modify(int p, T val, int root, int l, int r) {
        if(r - l < 2) {
            t[root] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if(p < mid) modify(p, val, root<<1, l, mid);
        else modify(p, val, root<<1|1, mid, r);

        t[root] = combine(t[root<<1], t[root<<1|1]);
    }

    void modify(int p, T val) {
        modify(p, val, 1, 0, n);
    }

    T query(int x, int y, int root, int l, int r) {
        if(l >= y || r <= x) return {INT_MIN, -1};
        if(l >= x && r <= y) return t[root];
        int mid = (l + r) >> 1;
        return combine(query(x, y, root<<1, l, mid), query(x, y, root<<1|1, mid, r));
    }

    T query(int x, int y) {
        return query(x, y, 1, 0, n);
    }
};
