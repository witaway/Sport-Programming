#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ff first
#define ss second

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const ll inf = 1e9+7;

///f - фактический поток, c - вообще поток, g - граф.
///d - метка вершины
///n, m, start, finish - кол-во вершин, кол-во рёбер, стартовая и конечная вершины.
vector<vector<int>> g, f, c;
vector<int> d;
int n, m, start, finish;

bool bfs() {
    
    ///С помощью bfs проставляем метки.
    queue<int> q;
    d.assign(n, -1);
    d[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        int curV = q.front();
        q.pop();
        for(int to : g[curV]) {
            ///Но приходим только в вершины, у которых поток не полный и у которых нет метки.
            if(f[curV][to] < c[curV][to] && d[to] == -1) {
                q.push(to);
                d[to] = d[curV] + 1;
            }
        }
    }
    
    return d[finish] != -1;
}

///С помощью dfs находим потоки.
int dfs(int v, int k) {
    if(!k) return 0; ///Выходим, если поток пустой.
    if(v == finish) return k; ///И выходим, если пришли в финиш.
    for(int to : g[v]) {
        if(d[to] != d[v] + 1) continue;
        ///Пропихиваем ребёнку максимальный поток, который в него поместится.
        int add = dfs(to, min(k, c[v][to] - f[v][to]));
        ///И если там что-тоесть, меняем фактический поток и возвращаем его.
        if(add != 0) {
            f[v][to] += add;
            f[to][v] -= add;
            ///Не волнуемся по поводу того, что он вернёт add только для одного ребёнка, 
            ///Потому что while в main запускает наш dfs очень много раз и каждый раз наш путь не будет повторяться
            ///Потому что мы меняем фактический поток и больше туда прийти не сможем.
            return add;
        }
    }
    ///Если ничего не изменилось, то кидаем ноль.
    return 0;
}

int main() {
    
    ///Вводим граф...
    cin >> n >> m;
    
    g.resize(n);
    f.assign(n, vector<int>(n, 0));
    c.assign(n, vector<int>(n, 0));
    
    start = 0;
    finish = n - 1;
    
    for(int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back(y);
        c[x][y] = w;
    }
    
    ///Пока у нас есть минимальный путь (bfs), то проталкиваем поток до тех пор, пока проталкивается (dfs)
    ///Если минимального пути через нет, bfs вернёт false
    ///Если мы больше не смогли протолкнуть свой поток, dfs тоже вернёт ноль.
    ll ans = 0;
    while(bfs()) {
        while(ll add = dfs(start, inf)) {
            ans += add;
        }
    }
    
    cout << ans;

    return 0;
}
