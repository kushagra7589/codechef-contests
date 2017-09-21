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

set<int> maxNodes;
ll distance1[MAX_SIZE];
bool visited[MAX_SIZE];
const int INF = 1e7;
int arr[510][510];
set<int> farthest;

ll bfs(int s, int N)
{
	for(int i = 0; i < N; i++)
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
	ll maxD = 0;
	int node = -1;
	for(int i = 0; i < N; i++)
	{
		if(maxNodes.find(i) == maxNodes.end())
		{
			maxD = max(maxD, distance1[i]);
		}
	}
	cout << "bfs with " << s << " max distance : " << maxD << endl;
	return maxD;
}

void print(int N)
{
	for(int i = 0; i < N; i++)
	{
		cout << i << endl;
		for(auto &j: graph[i])
		{
			cout << j << " ";
		}
		cout << endl;
		cout << "--------------------------" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t; 
	while(t--)
	{
		maxNodes.clear();
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
					maxNodes.insert(get_node(i, j));
				}
			}
		}
		make_graph(n, m);
		// print(n*m);
		int s = *maxNodes.begin();
		int far = bfs(s, n*m);
		if(far)
		{
			cout << "max dist : " << far << endl;
			ll res = 0;
			for(int i = 0; i < n*m; i++)
			{
				if(distance1[i] == far && maxNodes.find(i) == maxNodes.end())
					farthest.insert(i);
			}
			cout << "Farthest from " << s << endl;
			for(auto &k : farthest)
			{
				cout << k << " ";
			}
			cout << endl;
			for(auto &u : farthest)
			{
				int x = bfs(u, n*m);
				cout << "distance from farthest : " << u << endl;
				ll ans = INF;
				for(auto &k : maxNodes)
				{
					cout << k << " " << distance1[k] << endl;
					ans = min(ans, distance1[k]);
				}
				res = max(res, ans);
			}
			cout << res << endl;
		}
		else
		{
			cout << 0 << endl;
		}
		for(int i = 0; i < n*m; i++)
			graph[i].clear();
	}
	return 0;
}