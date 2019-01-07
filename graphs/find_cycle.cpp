const int still_out = 0, already_out = 2, in = 1; 
int cycle_start, cycle_end;
vector<vector<int>> g; ///Adjacency list
vector<char> status; ///Status of vertex
vector<int> p; 

///https://neerc.ifmo.ru/wiki/index.php?title=Использование_обхода_в_глубину_для_поиска_цикла
bool dfs(int v) {
	status[v] = in;
	for(auto to : g[v]) {
	        if(status[to] == still_out) {
			p[to] = v;
			if(dfs(to)) return true;
		}
		else if(status[to] == in) {
			cycle_end = v;
			cycle_start = to;
			return true;
		}
	}
	status[v] = already_out;
	return false;
}

...

p.assign(n, -1);
status.assign(n, 0);

cycle_start = -1;
cycle_end   = -1;
for(int i = 0; i < g.size(); ++i) {
	if(dfs(i)) break;
}

if(cycle_start == -1) {
	///Graph is acyclic
} else {
	///Graph is cyclic
	
	vector<int> cycle;
	cycle.push_back(cycle_start);
	for (int v = cycle_end; v != cycle_start; v = p[v]) {
		cycle.push_back (v);
	}
	cycle.push_back(cycle_start);
	
	reverse (cycle.begin(), cycle.end());

        ///Now cycle is a list of vertexes that are in cycle
	///WELL DONE!
}
