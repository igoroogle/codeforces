#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
int vl[11];
int n;
vector < vector<int> > g;
vector<char> cl;
vector<int> p;
int cycle_st, cycle_end;

vector<char> cl2;
vector<int> p2;
vector<int> cycle;
int cycle_st2, cycle_end2;
int ua, ub;

bool dfs2 (int v) {
	cl2[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if ((v == ua) && (to == ub)) {
            continue;
		}

		if (cl2[to] == 0) {
			p2[to] = v;
			if (dfs2 (to))  return true;
		}
		else if (cl2[to] == 1) {
			cycle_end2 = v;
			cycle_st2 = to;
			return true;
		}
	}
	cl2[v] = 2;
	return false;
}

bool dfs (int v) {
	cl[v] = 1;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (cl[to] == 0) {
			p[to] = v;
			if (dfs (to))  return true;
		}
		else if (cl[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			return true;
		}
	}
	cl[v] = 2;
	return false;
}

//map<pair<int, int>> gp;

int main() {
    ios_base::sync_with_stdio(0);
    int m, u, v, kl = 0;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
    }
    p.assign (n, -1);
	cl.assign (n, 0);
	cycle_st = -1;
	for (int i=0; i<n; ++i)
		if (dfs (i))
			break;

	if (cycle_st == -1) {
		cout << "YES\n";
		return 0;
	}
	else {
		cycle.push_back (cycle_st);
		for (int v=cycle_end; v!=cycle_st; v=p[v])
			cycle.push_back (v);
		cycle.push_back (cycle_st);
		reverse (cycle.begin(), cycle.end());
	}

    for (int k = 0; k < int(cycle.size()) - 1; ++k) {
        p2.clear();
        cl2.clear();
        ua = cycle[k];
        ub = cycle[k + 1];
        p2.assign (n, -1);
        cl2.assign (n, 0);
        cycle_st = -1;
        for (int i=0; i<n; ++i) {
		if (dfs2 (i))
			break;
        }
        if (cycle_st == -1) {
            cout << "YES\n";
            return 0;
        }

    }

    cout << "NO\n";
}
