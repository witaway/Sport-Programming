#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ff first
#define ss second
#define writeln(that_arr,that_method) for(auto &that_iterator : that_arr) that_method << that_iterator << " "; that_method << endl;
#define matrix_writeln(that_matrix,that_method) for(auto &that_iterator1 : that_matrix) {for(auto &that_iterator2 : that_iterator1) that_method << that_iterator2 << " "; that_method << endl;}
#define map_writeln(that_map,that_method) for(auto &that_iterator : that_map) that_method << that_iterator.ff << " : " << that_iterator.ss << endl;

using ll  = long long;
using ld  = long double;
using ull = unsigned long long;
using ui  = unsigned int;

const double pi = 3.14159265358979323;
const double eps = 0.0000001;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#define cerr if(0) cerr
#endif



    return EXIT_SUCCESS;
}
