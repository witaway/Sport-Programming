#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define writeln(that_arr,that_method) for(auto &that_iterator : that_arr) that_method << that_iterator << " "; that_method << endl;
#define matrix_writeln(that_arr,that_method) for(auto &that_iterator1 : that_matrix) {for(auto &that_iterator2 : that_iterator1) that_method << that_iteartor2 << " "; that_method << endl;}
#define map_writeln(that_map,that_method) for(auto &that_iterator : that_map) that_method << that_iterator.ff << " : " << that_iterator.ss << endl;
#define halt() exit(EXIT_SUCCESS)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

const double pi = 3.14159265358979323;
const double eps = 0.0000001;

const ll inf = 1e16;
const int M = 1e9 + 7;
const int N = 2e5 + 7;

vector<pair<int,ll> > g[N][5];
vector<ll> d, c;

///Hi There!
int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    halt();
}
