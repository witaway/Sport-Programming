int n, m;
vector<vector<int>> g, gr; //are graph and inverted graph
vector<bool> used;
vector<int> order, component;

//It is topological sort
void dfs1(int v) {
	used[v] = true;
	for(auto to : g[v]) {
        	if(!used[to]) {
            		dfs1(to);
        	}
	}
	order.push_back(v);
}

//if we can reach the edge it is part of new strong connected component
void dfs2 (int v) {
	used[v] = true;
	component.push_back(v);
	for(auto to : gr[v]) {
        	if(!used[to]) {
            		dfs2(to);
       		}
	}
}

int main() {

	cin >> n >> m;
	g.resize(n);
	gr.resize(n);

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gr[b].push_back(a);
	}

	used.assign(n, false);
	for(int i = 0; i < n; ++i) {
		if(!used[i]) {
			dfs1 (i);
		}
	}

	reverse(order.begin(), order.end());
	used.assign(n, false);
	for(int i = 0; i < n; ++i) {
		int v = order[i]
		if(!used[v]) {
			dfs2(v);
			out_array(component);
			component.clear();
		}
	}

}
