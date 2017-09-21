#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e3+10;
const ll INF = 1e10+10;

ll arr[MAX_SIZE][MAX_SIZE];

set<pair<ll, pair< pair <int, int>, int > > > row_sum, col_sum;
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
				cin >> arr[i][j];
			}
		}
		ll row_min_sum = INF;
		ll grand_grand = INF;
		for(int i=0; i<n; i++)
		{
			ll sum = 0;
			ll start = 0, end = 0;
			ll min_sum = INF;
			for(int j=0; j<m; j++)
			{
				sum += arr[i][j];
				if(sum < min_sum)
				{
					min_sum = sum;
					end = j;
				}
				if(sum > 0)
				{
					sum = 0;
					start = j+1;
				}
			}
			if(min_sum >= 0)
				start = end;
			row_sum.insert(mp(min_sum, mp(mp(start, end), i)));
			if(row_min_sum > min_sum)
			{
				row_min_sum = min_sum;
			}
		}
		for(auto i : row_sum)
		{

			if(i.F == row_min_sum)
			{
				ll sum = 0;
				ll min_sum = 0;
				ll total_sum = 0;
				ll grand_sum = INF;
				for(int j = i.S.F.F; j <= i.S.F.S; j++)
				{
					sum = 0;
					min_sum = 0;
					for(int row = i.S.S+1; row < n; row++)
					{
						sum += arr[row][j];
						if(sum < min_sum)
						{
							min_sum = sum;
						}
					}
					total_sum += min_sum;
					for(int row = i.S.S-1; row >= 0; row--)
					{
						sum += arr[row][j];
						if(sum < min_sum)
						{
							min_sum = sum;
						}
					}
					total_sum += min_sum;
					if(total_sum < grand_sum)
						grand_sum = total_sum;
				}
				grand_sum += i.F;
				if(grand_grand > grand_sum)
					grand_grand = grand_sum;
			}
			else
				break;
		}

		ll col_min_sum = INF;
		for(int i=0; i<m; i++)
		{
			ll sum = 0;
			ll start = 0, end = 0;
			ll min_sum = INF;
			for(int j=0; j<n; j++)
			{
				sum += arr[j][i];
				if(sum < min_sum)
				{
					min_sum = sum;
					end = j;
				}
				if(sum > 0)
				{
					sum = 0;
					start = j+1;
				}
			}
			if(min_sum >= 0)
				start = end;
			col_sum.insert(mp(min_sum, mp(mp(start, end), i)));
			if(col_min_sum > min_sum)
			{
				col_min_sum = min_sum;
			}
		}
		for(auto i : col_sum)
		{

			if(i.F == col_min_sum)
			{
				ll sum = 0;
				ll min_sum = 0;
				ll total_sum = 0;
				ll grand_sum = INF;
				for(int j = i.S.F.F; j <= i.S.F.S; j++)
				{
					sum = 0;
					min_sum = 0;
					for(int col = i.S.S+1; col < m; col++)
					{
						sum += arr[j][col];
						if(sum < min_sum)
						{
							min_sum = sum;
						}
					}
					total_sum += min_sum;
					for(int col = i.S.S-1; col >= 0; col--)
					{
						sum += arr[j][col];
						if(sum < min_sum)
						{
							min_sum = sum;
						}
					}
					total_sum += min_sum;
					if(total_sum < grand_sum)
						grand_sum = total_sum;
				}
				grand_sum += i.F;
				if(grand_grand > grand_sum)
					grand_grand = grand_sum;
			}
			else
				break;
		}
		cout << grand_grand << endl;
	}
	return 0;
}