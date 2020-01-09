template<typename T>
struct PersistentSegtree {

    struct Node {
        int l = -1;
        int r = -1;
        T sum = 0;
        Node(int l, int r, vector<Node> &t) : l(l), r(r), sum(t[l].sum + t[r].sum) {}
        Node(T x) : sum(x) {}
        Node() {}
    };

    vector<int> history;
    vector<Node> t;
    int st;

    PersistentSegtree(int n) {

        st = 1;
        while(st < n) st *= 2;
        history.push_back(build(0, st - 1));

    }

    PersistentSegtree(vector<int> &a) {

        st = 1;
        while(st < a.size()) st *= 2;
        history.push_back(build(0, st - 1));

    }

    int build(int cl, int cr, vector<int> &a) {

        if(cl == cr) {
            t.push_back(Node(a[cl]));
            return t.size() - 1;
        }

        int mid = (cl + cr) / 2;
        t.push_back(Node(build(cl, mid), build(mid + 1, cr), t));
        return t.size() - 1;
    }

    T query(int cl, int cr, int v, int l, int r) {

        if(cl > r || cr < l) return 0;
        if(cl >= l && cr <= r) return t[v].sum;

        int mid = (cl + cr) / 2;

        return query(cl, mid, t[v].l, l, r) +
               query(mid + 1, cr, t[v].r, l, r);
    }

    T query(int t, int l, int r) {

        return query(0, st - 1, history[t], l, r);
    }

    void modify(int t, int p, T x) {

        history.push_back(modify(0, st - 1, history[t], p, x));
    }

    int modify(int cl, int cr, int v, int p, int x) {

        if(cl == cr) {
            t.push_back(Node(x));
            return t.size() - 1;
        }

        int mid = (cl + cr) / 2;

        if(p <= mid) {
            int new_l = modify(cl, mid, t[v].l, p, x);
            t.push_back(Node(new_l, t[v].r, t));
            return t.size() - 1;
        }
        else {
            int new_r = modify(mid + 1, cr, t[v].r, p, x);
            t.push_back(Node(t[v].l, new_r, t));
            return t.size() - 1;
        }

    }

};
