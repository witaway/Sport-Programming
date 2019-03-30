int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
 
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main() {
	... чтение графа ...
 
	mt.assign (k, -1);
	vector<char> used1 (n);
	for (int i=0; i<n; ++i)
		for (size_t j=0; j<g[i].size(); ++j)
			if (mt[g[i][j]] == -1) {
				mt[g[i][j]] = i;
				used1[i] = true;
				break;
			}
	for (int i=0; i<n; ++i) {
		if (used1[i])  continue;
		used.assign (n, false);
		try_kuhn (i);
	}
 
	for (int i=0; i<k; ++i)
		if (mt[i] != -1)
			printf ("%d %d\n", mt[i]+1, i+1);
}
