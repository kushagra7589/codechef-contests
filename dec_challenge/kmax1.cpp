#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;
const int K = 16;
const int ZERO = 0;


ll arr[MAX_SIZE];
set< pll > give_max;
ll Table[MAX_SIZE][K+1];

void buildTable(int n)
{
	for(int i=0; i<n; i++)
		Table[i][0] = arr[i];
	for(int j=1; j<=K; j++)
	{
		for(int i=0; i<=n-(1<<j); i++)
		{
			Table[i][j] = max(Table[i][j-1], Table[i + (1 << (j-1))][j-1]);
			// if(arr[Table[i][j-1]] > arr[Table[i + (1 << (j-1))][j-1]])
			// 	Table[i][j] = Table[i][j-1];
			// else
			// 	Table[i][j] = Table[i + (1 << (j-1))][j-1];
		}
	}
}

ll query(int l,  int r)
{
	ll answer = ZERO;
	for(int j=K; j>=0; j--)
	{
		if(l + (1<<j) - 1 <= r)
		{
			answer = max(answer, Table[l][j]);
			// if(arr[Table[l][j]] > arr[answer])
			// 	answer = Table[l][j];
			l += (1 << j);
		}
	}
	return answer;
}

ll bs(ll p, ll n)
{
	ll l = 1;
	ll u = (n*(n+1))/2;
	while(l < u)
	{
		ll mid = (l+u)/2;
		if(mid*(mid + 1) < 2 * p)
			l = mid + 1;
		else
			u = mid;
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		ll n, m;
		cin >> n >> m;

		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		arr[MAX_SIZE-1] = 0;
		buildTable(n);
		
		ll p;

		vector< vector<ll> > treemap(MAX_SIZE, vector<ll>());

		for(int i=1; i<=n; i++)
		{
			int j=i-1;
			while(j < n)
			{
				treemap[i].pb(query(j-i+1, j));
				j++;
			}
			sort(treemap[i].begin(), treemap[i].end(), greater<ll>());
		}

		while(m--)
		{
			cin >> p;
			ll k = bs(p, n);
			ll bucket_size = n+1-k;
			ll start = (k * (k-1))/2;
			ll num = p - start - 1;
			cout << treemap[bucket_size][num] << endl;
		}

		treemap.clear();
	}
	return 0;
}