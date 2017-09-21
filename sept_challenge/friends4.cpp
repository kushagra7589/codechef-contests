#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e3+10;

bool graph[MAX_SIZE][MAX_SIZE];

int color[MAX_SIZE];

bool bfs(int x, int n)
{
	queue<int> q1;
	q1.push(x);
	while(!q1.empty())
	{
		int s = q1.front(); q1.pop();
		for(int i=1; i<=n ; i++)
		{
			if(graph[s][i] == true)
			{
				if(color[i] == 0)
				{
					color[i] = -color[s];
					q1.push(i);
				}
				else if(color[i] == color[s])
					return false;
			}
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
				if(i!=j)
					graph[i][j] = true;
			}
			graph[i][i] = false;
			color[i] = 0;
		}
		while(m--)
		{
			cin >> x >> y;
			graph[x][y] = false;
			graph[y][x] = false;
		}
		bool flag = true;
		for(int i=1; i<=n; i++)
		{
			if(color[i] == 0)
			{
				color[i] = 1;
				flag = bfs(i, n);
				if(!flag)
					break;
			}
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";	
	}
	return 0;
}