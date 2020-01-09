template<typename T>
struct PersistentSegtree {

    struct Node {
        Node* l = nullptr;
        Node* r = nullptr;
        T sum = 0;
        Node(Node* l, Node* r) : l(l), r(r), sum(l->sum + r->sum) {}
        Node(T x) : sum(x) {}
        Node() {}
    };

    vector<Node*> history;
    int st;

    PersistentSegtree(int n) {

        st = 1;
        while(st < n) st *= 2;
        history.push_back(build(0, st - 1));

    }

    Node* build(int cl, int cr) {

        if(cl == cr) {
            return new Node(0);
        }

        int mid = (cl + cr) / 2;
        return new Node(build(cl, mid),
                        build(mid + 1, cr));

    }

    T query(int cl, int cr, Node* v, int l, int r) {

        if(cl > r || cr < l) return 0;
        if(cl >= l && cr <= r) return v->sum;

        int mid = (cl + cr) / 2;

        return query(cl, mid, v->l, l, r) +
               query(mid + 1, cr, v->r, l, r);
    }

    T query(int t, int l, int r) {

        return query(0, st - 1, history[t], l, r);
    }

    void modify(int t, int p, T x) {

        history.push_back(modify(0, st - 1, history[t], p, x));
    }

    Node* modify(int cl, int cr, Node* v, int p, int x) {

        if(cl == cr) {
            return new Node(x);
        }

        int mid = (cl + cr) / 2;

        if(p <= mid) {
            Node* new_l = modify(cl, mid, v->l, p, x);
            return new Node(new_l, v->r);
        }
        else {
            Node* new_r = modify(mid + 1, cr, v->r, p, x);
            return new Node(v->l, new_r);
        }

    }

};
