///[l, r]
struct segtree {

    vector<long long> t, lazy; //Tree and value that we push
    vector<bool> need; //True is ith vertex needs pushing.
    long long st; //Number of first element in bottom row.

    segtree(int n) {

        st = 1;
        while(st < n) st *= 2;

        t.assign(st * 2, 0);
        lazy.assign(st * 2, 0);
        need.assign(st * 2, false);

    }

    void init() {
        for(int i = st - 1; i >= 1; i--) {
            t[i] = t[i * 2] + t[i * 2 + 1];
        }
    }

    void push(int v, int l, int r) {
        //We push only if we need.
        //Alternative is if(lazy[v] != 0), but this alternative is dangerous.
        if(need[v]) {

            int mid = (l + r) / 2;

            //Pushing value to tree
            t[v * 2] = (mid - l + 1) * lazy[v];
            t[v * 2 + 1] = (r - mid) * lazy[v];

            //Next we push this to the subtrees/
            need[v * 2] = true;
            need[v * 2 + 1] = true;
            lazy[v * 2] = lazy[v];
            lazy[v * 2 + 1] = lazy[v];

            //And now we dont have not need in pushing in that vertex.
            lazy[v] = 0;
            need[v] = false;
        }
    }

    void modify(int cl, int cr, int v, int l, int r, long long x) {
        if(cl > r || cr < l) return;
        ///REMEMBER IT!!!
        if(cl >= l && cr <= r) {
            lazy[v] = x; need[v] = true;
            t[v] = (cr - cl + 1) * x;
            return;
        }

        ///You should to push in every recursive operation before recursive descent to children.
        push(v, cl, cr);

        int mid = (cl + cr) / 2;
        modify(cl, mid, v * 2, l, r, x);
        modify(mid + 1, cr, v * 2 + 1, l, r, x);

        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    void modify(int l, int r, long long x) {
        ///Be attentive with it!
        ///[0, a.size() - 1] IS INCORRECT!
        ///[0, st - 1] IS NEEDED!
        modify(0, st - 1, 1, l, r, x);
    }

    long long query(int cl, int cr, int v, int l, int r) {
        if(cl > r || cr < l) return 0;
        if(cl >= l && cr <= r) return t[v];

        ///You should to push in every recursive operation before recursive descent to children.
        ///Idk why there is this condition, it is magic.
        if(cl != cr) push(v, cl, cr);

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
