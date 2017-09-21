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
const int ZERO = MAX_SIZE-1;


ll arr[MAX_SIZE];
ll Table[MAX_SIZE][K+1];

void buildTable(int n)
{
	for(int i=0; i<n; i++)
		Table[i][0] = i;
	for(int j=1; j<=K; j++)
	{
		for(int i=0; i<=n-(1<<j); i++)
		{
			// Table[i][j] = max(arr[Table[i][j-1]], arr[Table[i + (1 << (j-1))][j-1]]);
			if(arr[Table[i][j-1]] > arr[Table[i + (1 << (j-1))][j-1]])
				Table[i][j] = Table[i][j-1];
			else
				Table[i][j] = Table[i + (1 << (j-1))][j-1];
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
			// answer = max(arr[answer], arr[Table[l][j]]);
			if(arr[Table[l][j]] > arr[answer])
				answer = Table[l][j];
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

void check(int l, int r, int bucket_size)
{
	if(r-l+1 < bucket_size)
		return;
	int index = query(l, r);
	int start = max(l, index - bucket_size + 1);
	int end = min(r, index + bucket_size - 1);
	int c = end - start + 1;
	give_max.insert(mp(-1 * arr[index], c - bucket_size +  1));
	check(l, start - 1 + bucket_size - 1, bucket_size);
	check(end + 1 - bucket_size + 1, r, bucket_size);
}

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
			cin >> arr[i];
		}
		arr[MAX_SIZE-1] = 0;
		buildTable(n);
		
		ll p;

		while(m--)
		{
			give_max.clear();
			cin >> p;
			ll k = bs(p, n);
			check(0, n-1, n-k+1);
			ll start = (k * (k-1))/2;
			ll num = p - start;
			int i = 0;
			auto it = give_max.begin();
			while(i < num && it != give_max.end())
			{
				i += (*it).S;
				if(i < num && it != give_max.end())
					it++;
			}
			cout << -1 * (*it).F << endl;	
		}
	}
	return 0;
}