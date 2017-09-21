#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1010;
char reser[MAX_SIZE][MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) 
	{
		int n, m;
		cin >> n >> m;
		for(int i=0; i<=m+1; i++)
		{
			reser[0][i] = 'A';
			reser[n+1][i] = 'B';
		}
		for(int i=0; i<=n+1; i++)
		{
			reser[i][0] = 'A';
			reser[i][m+1] = 'A';
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cin >> reser[i][j];
			}
		}
		int flag = 1;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(reser[i][j] == 'B')
				{
					if(reser[i+1][j])
				}
			}
		}
	}
	return 0;
}