#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

ll arr[MAX_SIZE];
vector< pll > compressed;
vector< ll > prefix_sum;

int binarySearch(int s, int N)
{
	int mid;
	int low = 0;
	int hi = N;
	while(low < hi)
	{
		mid = (low+hi)/2;
		if(prefix_sum[mid] <x s)
			low = mid+1;
		else
			hi = mid;
	}
	return low;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int i=0;
	ll count = 0;
	while(i < n)
	{
		count = 1;
		while(arr[i] == arr[i+1] && i < n-1)
		{
			i++;
			count++;
		}
		compressed.pb(mp(arr[i], count));
		i++;
	}
	int N = compressed.size();
	prefix_sum.resize(N);
	prefix_sum[0] = compressed[0].S;
	for(int i=1; i<n; i++)
		prefix_sum[i] = prefix_sum[i-1] + compressed[i].S;
	int l, r, k, low, hi, s, mid;
	for(int i=0; i<m; i++)
	{
		cin >> l >> r >> k;
		// low = 0;
		// hi = n;
		s = (l+r)/2;
		int left = binarySearch(l, N);
		int right = binarySearch(r, N);
		int middle = binarySearch(s, N);
		cout << "left = " << left << " right = " << right << endl;
		compressed[left].S -= (l - prefix_sum[left-1]);
		compressed[right].S -= (prefix_sum[right]-r);
		cout << "Changed values : " << compressed[left].S << " " << compressed[right].S << endl;
		if(compressed[middle].S >= k)
			cout << compressed[middle].F << endl;
		else
			cout << -1 << endl;
		compressed[left].S += (l - prefix_sum[left-1]);
		compressed[right].S += (prefix_sum[right]-r);
	}
	return 0;
}