#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_SIZE = 500 * 500 + 10;

#define pb push_back

vector<int> graph[MAX_SIZE];

int n, m;

int get_node(int i, int j)
{
	return i*m + j;
}

void make_graph(int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int curr = get_node(i, j);
			if(i - 1 >= 0) graph[curr].pb(get_node(i - 1, j));
			if(i + 1 < n) graph[curr].pb(get_node(i + 1, j));
			if(j - 1 >= 0) graph[curr].pb(get_node(i, j - 1));
			if(j + 1 < m) graph[curr].pb(get_node(i, j + 1));
			if(i - 1 >= 0 && j - 1 >= 0) graph[curr].pb(get_node(i - 1, j - 1));
			if(i - 1 >= 0 && j + 1 < m) graph[curr].pb(get_node(i - 1, j + 1));
			if(i + 1 < n && j - 1 >= 0) graph[curr].pb(get_node(i + 1, j - 1));
			if(i + 1 < n && j + 1 < m) graph[curr].pb(get_node(i + 1, j + 1));
		}
	}
}

ll distance1[MAX_SIZE];
bool visited[MAX_SIZE];
int arr[501][501];

const int INF = 1e7;

void bfs(int s, int N)
{
	for(int i = 0; i <= N; i++)
	{
		distance1[i] = INF;
		visited[i] = false;
	}
	distance1[s] = 0;
	queue<int> q;
	visited[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto &v : graph[u])
		{
			if(!visited[v])
			{
				visited[v] = true;
				distance1[v] = distance1[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t; 
	while(t--)
	{
		cin >> n >> m;
		int max_I = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				max_I = max(max_I, arr[i][j]);
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(arr[i][j] == max_I)
				{
					graph[n*m].pb(get_node(i, j));
				}
			}
		}
		make_graph(n, m);
		bfs(n*m, n*m);
		ll ans = 0;
		for(int i = 0; i < n*m; i++)
		{
			ans = max(ans, distance1[i]);
		}
		cout << ans - 1 << endl;
		for(int i = 0; i <= n*m; i++)
			graph[i].clear();
	}
	return 0;
}