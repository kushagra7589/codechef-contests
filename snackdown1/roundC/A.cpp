#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::	sync_with_stdio(false);

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;
typedef long double ld;

#define pll pair<ll, ll>
#define vll vector<ll>

const int M = 1e9 + 7;
const int INF = 1e9;

vll a;
vll dp;

int main()
{
	fast_io();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		a.resize(n + 1);
		dp.resize(n + 1);
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		dp[n] = a[n];
		ll sum = 0;
		ll k = 1;
		for(int i = n - 1; i > 0; i--)
		{
			dp[i] = ((((((k * a[i]) % M) + dp[i + 1]) % M) + ((a[i] * dp[i + 1]) % M)) - (a[i] * sum) % M + sum + M) % M;
			sum = (sum + dp[i + 1]) % M;
			k = (k * (ll)2) % M;
		}
		cout << dp[1] << endl;
	}
	return 0;
}