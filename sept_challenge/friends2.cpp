#include <bits/stdc++.h>
 
using namespace std;
const int MAX_SIZE = 1e3+10;
 
vector < set<int> > graph(MAX_SIZE);
bool in_table[MAX_SIZE];
 
void create_edge(int x, int y)
{
	graph[x].insert(y);
}
 
void create_set(set<int> &S, const set<int> &other, int x)
{
	S.clear();
	S.insert(x);
	in_table[x] = true;
	for(set<int>::iterator i = graph[x].begin(); i != graph[x].end(); i++)
	{	
		if(other.find(*i) == other.end())
		{	
			S.insert(*i);
			in_table[*i] = true;
		}
	}
}
 
void make_know(set<int> &S, int n)
{
	if(S.size() != 1)
	{
		set<int> temp (S);
		set<int>::iterator start = temp.begin(), finish = temp.end();
		start++;
		finish--;
		for(set<int>::iterator i = start; i != finish; i++)
		{	
			set<int>::iterator next_start = i;
			next_start++;
			for(set<int>::iterator j = next_start; j != temp.end(); j++)
			{
				if(graph[*i].find(*j) == graph[*i].end())
				{
					in_table[*j] = false;
				}
			}
		}
		for(int i=1; i<=n; i++)
		{
			if(in_table[i] == false)
			{
				if(S.find(i) != S.end())
				{
					S.erase(i);
				}
			}
		}
	}
}
 
void display_set(const set<int> &S, string a)
{
	cout << a << endl;
	for(set<int>::iterator i = S.begin(); i != S.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m;
	int x, y;
	set<int> table1;
	set<int> table2;
	while(t--)
	{	
		cin >> n >> m;
		if(m == 0)
		{
			cout << "NO\n";
		}
		else
		{
			for(int i=1; i<=n; i++)
			{
				in_table[i] = false;
			}
			for(int i=0; i<m; i++)
			{
				cin >> x >> y;
				create_edge(x, y);
				create_edge(y, x);
			}
			create_set(table1, table2, 1);
			make_know(table1, n);
			display_set(table1, "Table 1 : ");
			int flag = 0;
			int i;
			for(i=1; i<=n; i++)
			{
				if(in_table[i] == false)
				{
					flag  = 1;
					break;
				}
			}
			if(flag)
			{
				create_set(table2, table1, i);
				make_know(table2, n);
				display_set(table2, "Table 2 : "); 		
				int j = 0;
				int flag1 = 0;
				for(j=1; j <= n; j++)
				{
					if(in_table[j] == false)
					{
						flag1 = 1;
						break;
					}
				}
				if(flag1)
				{
					cout << "NO\n";
				}
				else
				{
					cout << "YES\n";
				}
			}
			else
			{
				cout << "YES\n";
			}
		}
		table1.clear();
		table2.clear();
		for(int i=1; i<=n; i++)
		{
			graph[i].clear();
		}
	}
	return 0;
}  