const int still_out = 0, already_out = 2, in = 1;
int cycle_start, cycle_end;
vector<vector<int>> g;
vector<char> status;
vector<int> p;

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

int main() {
	... чтение графа ...

	p.assign(n, -1);
	status.assign(n, 0);
	cycle_start = -1;
	for(int i = 0; i < g.size(); ++i) {
		if(dfs(i)) break;
	}

	if(cycle_start == -1) {
        cout << "Acyclic";
    }
	else {
		cout << "Cyclic" << endl;

		vector<int> cycle;
		cycle.push_back(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = p[v]) {
			cycle.push_back (v);
		}
		cycle.push_back(cycle_start);
		reverse (cycle.begin(), cycle.end());

        for(auto &x : cycle) {
            cout << x + 1 << " ";
        }
	}
}
