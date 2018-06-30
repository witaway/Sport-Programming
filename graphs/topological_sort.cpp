int n;
vector<vector<int>> g;
vector<bool> used;
vector<int> ans;

void dfs(int v) {
	used[v] = true;
	for(auto to : g[v]) {
		if(!used[to]) {
			dfs(to);
		}
	}
	ans.push_back(v);
}

void topological_sort() {
	used.assign(n, false);
	ans.clear();
	for(int i = 0; i < n; ++i) {
		if(!used[i]) {
			dfs(i);
		}
	}
	reverse(ans.begin(), ans.end());
}
