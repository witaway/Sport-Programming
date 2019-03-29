vector<int> a;
int f() {
    int e = 0;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(i == j) continue;
            if(abs(i - j) == abs(a[i] - a[j])) e++;
        }
    }
    return e;
}

...

srand(time(0));

int n;
cin >> n;
a.resize(n);

vector<int> ans(n);
double T = 10, c = 0.997;
int m = 100, e0, eans = INT_MAX;

for(int i = 1; i <= n; i++) {
    a[i - 1] = i;
}

e0 = f();
eans = INT_MAX;

while(T > 1e-4) {
    for(int iterato = 0; iterato < m; iterato++) {
        int p1 = rand() % n, p2 = rand() % n;
        if(p1 == p2) continue;
        swap(a[p1], a[p2]);
        int e1 = f();
        int d = e1 - e0;
        double x = exp((-1.0 * d) / T), alpha = (rand() % 1000) / 1000.0;
        if(d >= 0 && x < alpha) {
            swap(a[p1], a[p2]);
        } else {
            e0 = e1;
        }
        if(e0 < eans) {
            ans = a;
            eans = e0;
        }
    }
    T *= c;
}

writeln(ans, cout);
