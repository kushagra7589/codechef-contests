#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back

const int MAX_SIZE = 1e5+10;
ll arr[MAX_SIZE];
vector< pll > freq;
vector< ll > prefix_sum;

int bS(ll searchI, int n)
{
	int l = 0;
	int u = n;
	int mid;
	// cout << "Search Item : " << searchI <<endl; 
	while(l < u)
	{
		// printf("l = %d, u = %d\n", l, u);
		mid = (l+u)/2;
		if(prefix_sum[mid] < searchI)
		{
			l = mid + 1;
		}
		else
		{
			u = mid;
		}
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	int I = 1;
	int cnt = 0;
	while(I <= n)
	{
		cnt = 1;
		while(arr[I] == arr[I+1] && I < n)
		{
			cnt += 1;
			I++;
		}
		freq.pb(mp(arr[I], cnt));
		I++;
	}
	int N = freq.size();
	prefix_sum.resize(N);
	prefix_sum[0] = freq[0].S;
	for(int i=1; i<N; i++)
	{
		prefix_sum[i] = prefix_sum[i-1] + freq[i].S;
	}
	int l, r, k;
	while(m--)
	{
		cin >> l >> r >> k;
		int left = bS(l, N);
		int right = bS(r, N);
		int middle = bS((l+r)/2, N);
		freq[left].S = freq[left].S - (l - ((left > 0) ? prefix_sum[left-1] : 0)) + 1;
		freq[right].S = freq[right].S - (prefix_sum[right] - r);
		// printf("Left : %d Right : %d middle = %d\n", left, right, middle);
		// printf("Updated : f[l] = %d, f[r] = %d f[m] = %d\n" , (int)freq[left].S, (int)freq[right].S, (int)freq[middle].S);
		if(freq[middle].S >= k)
			cout << freq[middle].F << endl;
		else
			cout << -1 << endl;
		freq[left].S = freq[left].S + (l - ((left > 0) ? prefix_sum[left-1] : 0)) - 1;
		freq[right].S = freq[right].S + (prefix_sum[right] - r);
	}
	return 0;
}