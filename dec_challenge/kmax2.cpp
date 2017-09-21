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
const ll ZERO = MAX_SIZE-1;


ll arr[MAX_SIZE];
ll Table[MAX_SIZE][K+1];
map<ll, ll> numMap;

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

vector< ll > myArr;

ll bs(ll p, ll n)
{
	int l = 0;
	int u = n-1;
	while(l < u)
	{
		int mid = (l+u)/2;
		if(myArr[mid] < p)
			l = mid + 1;
		else
			u = mid;
	}
	return l;
}


void check(int l, int r)
{
	if(l > r)
		return;
	ll index = query(l, r);
	ll i = min(r - index, index - l);
	ll n = r-l+1;
	if(numMap.find(arr[index]) == numMap.end())
		numMap[arr[index]] = 0;
	numMap[arr[index]] += (n-2*i)*(i+1) + (i*(i+1));
	check(l, index - 1); 	
	check(index + 1, r);
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
		
		check(0, n-1);
		sort(arr, arr + n, greater<ll>());
		
		for(int i=0; i<n; i++)
		{
			myArr.pb(numMap[arr[i]]);
		}
		
		for(int i=1; i<n; i++)
		{
			myArr[i] += myArr[i-1];
		}
		
		ll p;
		while(m--)
		{
			cin >> p;
			ll k = bs(p, n);
			cout << arr[k] << endl;
		}
		
		myArr.clear();
		numMap.clear();
	}
	return 0;
}