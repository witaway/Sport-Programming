#pragma GGC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define endl "\n"
#define ff first
#define ss second
#define writeln(that_arr,that_method) for(auto &that_iterator : that_arr) that_method << that_iterator << " "; that_method << endl;
#define matrix_writeln(that_arr,that_method) for(auto &that_iterator1 : that_matrix) {for(auto &that_iterator2 : that_iterator1) that_method << that_iteartor2 << " "; that_method << endl;}
#define map_writeln(that_map,that_method) for(auto &that_iterator : that_map) that_method << that_iterator.ff << " : " << that_iterator.ss << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const double pi = 3.14159265358979323;
const double eps = 1e-7;

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



    return EXIT_SUCCESS;
}
