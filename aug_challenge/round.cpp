#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

int arr[MAX_SIZE];
int visited[MAX_SIZE];
int time1 = 1;
int initial_time1[MAX_SIZE];
int final_time1[MAX_SIZE];

void make_edge(vector< vector<int> > &graph, int x, int y)
{
	graph[x].push_back(y);
}

void dfs_visit(vector< vector<int> > &, int, int, int &);

int dfs(vector< vector<int> > &graph, int n)
{
	for(int i=1; i<=n; i++)
	{
		visited[i]=0;
	}
	time1 = 0;
	int cycle_num = 1;
	int count = 0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i] == 0)
		{
			dfs_visit(graph, i, cycle_num, count);
			cycle_num++;
		}
	}
	return count;
}

void dfs_visit(vector< vector<int> > &graph, int vertex, int flag, int &count)
{
	time1 = time1+1;
	initial_time1[vertex] = time1;
	visited[vertex] = flag;
	for(int i=0;i<graph[vertex].size(); i++)
	{
		int u = graph[vertex][i];
		if(visited[u] == flag)
		{
			count += time1+1 - initial_time1[u];
		}
		else if(visited[u] == 0)
		{
			dfs_visit(graph, u, flag, count);
		}
	}
	time1 += 1;
	final_time1[vertex] = time1; 
}

void display(vector< vector<int> > &graph, int n)
{
	for(int i=1; i<=n; i++)
	{
		cout<<i;
		for(int j=0; j<graph[i].size(); j++)
		{
			cout<<"-->"<<graph[i][j];
		}
		cout<<endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		vector< vector<int> > graph(n+1);
		for(int i=1; i<=n; i++)
		{
			cin>>arr[i];
			make_edge(graph, i, (i+1+arr[i])%n==0?n:((i+1+arr[i])%n));
		}
		// display(graph, n);
		int conn = dfs(graph, n);
		cout<<conn<<endl;
		// graph.clear();
	}
	return 0;
}