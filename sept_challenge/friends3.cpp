#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e3+10;

vector< set<int> > graph(MAX_SIZE);

int color[MAX_SIZE];

void create_edge(int x, int y)
{
	graph[x].erase(y);
}

bool bfs(int x)
{
	queue<int> q1;
	q1.push(x);
	while(!q1.empty())
	{
		int s = q1.front();
		q1.pop();
		for(set<int>::iterator i = graph[s].begin(); i != graph[s].end(); i++)
		{
			if(color[*i] == 0)
			{ 
				color[*i] = -color[s];
				q1.push(*i);
			}
			else if(color[*i] == color[s])
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m;
	int x, y;
	while(t--)
	{
		cin >> n >> m;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(i != j)
					graph[i].insert(j);
			}
		}
		for(int i=0; i<=n; i++)
		{
			color[i] = 0;
		}
		while(m--)
		{
			cin >> x >> y;
			create_edge(x, y);
			create_edge(y, x);
		}
		bool flag = true;
		for(int i=1; i<=n; i++)
		{
			if(color[i] == 0)
			{
				color[i] = 1;
				flag  = bfs(i);
				if(!flag)
				{
					break;
				}
			}
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		for(int i=1; i<=n; i++)
		{
			graph[i].clear();
		}
	}
	return 0;
}