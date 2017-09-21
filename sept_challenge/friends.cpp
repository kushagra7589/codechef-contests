#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3+10;

vector< vector<int> > graph(MAX_SIZE);

int parent[MAX_SIZE];
bool visited[MAX_SIZE];
int cycles = 0;

void create_edge(int x, int y) {
	graph[x].push_back(y);
}

void dfs_visit(int s)
{
	visited[s] = true;
	for(unsigned int i=0; i<graph[s].size(); i++) {
		int u = graph[s][i];
		if(parent[u] == -1)
			parent[u] = s;
		if(visited[u] == false) {
			dfs_visit(u);x	
		}
		else if(visited[u] == true && parent[u] != s) {
			cout << "CHILD : " << u << " PARENT : " << s <<  endl;
			cycles += 1;
		}
	}
}

void dfs(int n)
{
	for(int i=1; i<=n; i++) {
		if(visited[i] == false) {
			dfs_visit(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	int n, m;
	cin >> t;
	int x, y;
	while(t--) {
		cin >> n >> m;
		for(int i=1; i<=n; i++) {
			visited[i] = false;
			parent[i] = -1;
		}
		for(int i=0; i<m; i++) {
			cin >> x >> y;
			create_edge(x, y);
			create_edge(y, x);
		}
		dfs(n);
		cout << cycles << endl;
	}
	return 0;
}