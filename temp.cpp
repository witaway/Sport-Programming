vector<vector<int>> nxt;
vector<int> k;
int sz = 1;

void add(int x) {
    int v = 0;
    for(int i = 30; i >= 0; i--) {
        int to = (((1 << i) & x) > 0 ? 1 : 0);
        if(nxt[v][to] == 0) {
            sz++;
            nxt[v][to] = sz;
        }
        v = nxt[v][to];
        k[v]++;
    }
}

void del(int x) {
    int v = 0;
    for(int i = 30; i >= 0; i--) {
        int to = (((1 << i) & x) > 0 ? 1 : 0);
        v = nxt[v][to];
        k[v]--;
    }
}

int mx_xor(int x) {
    int v = 0, ans = 0;
    for(int i = 30; i >= 0; i--) {
        int to = (((1 << i) & x) > 0 ? 0 : 1);
        if(nxt[v][to] == 0 || k[nxt[v][to]] == 0) to = !to;
        if(to) ans += (1 << i);
        v = nxt[v][to];
    }
    return ans;
}

...

int main() {
	
    nxt.assign(5e6, vector<int>(2, 0));
    k.assign(5e6, 0);

    int q;
    cin >> q;

    add(0);

    for(int it = 0; it < q; it++) {
        char type;
        int val;

        cin >> type >> val;
        if(type == '+') {
            add(val);
        } else
        if(type == '-') {
            del(val);
        } else {
            cout << (val ^ mx_xor(val)) << endl;
        }
    }

    return 0;
}
