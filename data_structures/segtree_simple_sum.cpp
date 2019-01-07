///[l, r]
struct segtree {

    vector<long long> t;
    long long st; //Number of first element in bottom row. 

    segtree(vector<long long> &a) {
        
        st = 1;
        while(st < a.size()) st *= 2;
        t.assign(st * 2, 0);
        
        ///Filling bottom row with elements of array a
        for(int i = 0; i < a.size(); i++) {
            t[st + i] = a[i];
        }
        
        init();
    }

    ///Init tree.
    void init() {
        for(int i = st - 1; i >= 1; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void modify(int cl, int cr, int v, int p, int x) {
        ///Do not forget about it.
        if(cl == cr) {
            t[v] = x;
            return;
        }

        int mid = (cl + cr) / 2;
        if(p <= mid) modify(cl, mid, v * 2, p, x);
        else         modify(mid + 1, cr, v * 2 + 1, p, x);

        ///And about it.
        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    void modify(int p, int x) {
        ///Be attentive with it!
        ///[0, a.size() - 1] IS INCORRECT!
        ///[0, st - 1] IS NEEDED!
        modify(0, st - 1, 1, p, x);
    }

    long long query(int cl, int cr, int v, int l, int r) {
        if(cl > r || cr < l) return 0;
        if(cl >= l && cr <= r) return t[v];
        int mid = (cl + cr) / 2;
        return query(cl, mid, v * 2, l, r) +
               query(mid + 1, cr, v * 2 + 1, l, r);
    }

    long long query(int l, int r) {
        ///Be attentive with it!
        ///[0, a.size() - 1] IS INCORRECT!
        ///[0, st - 1] IS NEEDED!
        return query(0, st - 1, 1, l, r);
    }
};
