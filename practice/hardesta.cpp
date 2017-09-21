#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_SIZE = 1e3+10;
const ll INF = 1e10+10;

ll arr[MAX_SIZE][MAX_SIZE];
ll min_row[MAX_SIZE][MAX_SIZE];
ll min_col[MAX_SIZE][MAX_SIZE];
ll dp[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				min_row[i][j] = 0;
				min_col[i][j] = 0;
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin >> arr[i][j];
			}
		}
		for(int i=0; i<n; i++)
		{
			dp[m-1] = arr[i][m-1];
			min_row[i][m-1] += dp[m-1];
			for(int j=m-2; j>=0; j--)
			{
				dp[j] = min(arr[i][j], arr[i][j] + dp[j+1]);
				min_row[i][j] += dp[j];
			}
			dp[0] = arr[i][0];
			min_row[i][0] += dp[0];
			for(int j=1; j<m; j++)
			{
				dp[j] = min(arr[i][j], arr[i][j] + dp[j-1]);
				min_row[i][j] += dp[j];
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				min_row[i][j] -= arr[i][j];
				// cout << min_row[i][j] << " ";
			}
			// cout <<  endl;
		}
		for(int j=0; j<m; j++)
		{
			dp[n-1] = arr[n-1][j];
			min_col[n-1][j] += dp[n-1];
			for(int i=n-2; i>=0; i--)
			{
				dp[i] = min(arr[i][j], arr[i][j] + dp[i+1]);
				min_col[i][j] += dp[i];
			}
			dp[0] = arr[0][j];
			min_col[0][j] += dp[0];
			for(int i=1; i<n; i++)
			{

				dp[i] = min(arr[i][j], arr[i][j] + dp[i-1]);
				min_col[i][j] += dp[i];
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				min_col[i][j] -= arr[i][j];
				// cout << min_col[i][j] << " ";
			}
			// cout << endl;
		}
		ll ans = INF;
		ll temp;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				temp = min_row[i][j] + min_col[i][j];
				temp -= arr[i][j];
				if(temp < ans)
					ans = temp;
			}
		}
		cout << ans << endl;
	}
	return 0;
}