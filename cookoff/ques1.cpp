#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	long double n, m, b;
	long double ans = 0;
	while(t--)
	{
		ans = 0;
		cin >> n >> b >> m;
		while(n > 0)
		{
			// cout << "N = " << n << endl;
			ans += (floor((n+1)/2))*m;
			m = 2*m;
			// if(n > 1)
			n = floor(n/2);
			// else
			// 	n = 0;
			if(n > 0)
				ans += b;
			// cout << ans << endl;
		}
		ll res  = ans;
		cout << res << endl;
		// printf("%lld\n", );
	}
	return 0;
}