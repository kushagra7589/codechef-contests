#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int M = 1e9+7;

ll power2(ll a)
{
	ll res = 1;     
  	ll x = 2;
    while (a > 0)
    {
		if (a & 1)
            res = (res*x)%M;
        a = a>>1; 
        x = (x*x)%M;
    }
    return res%M;
}

int main()
{
	int t;
	cin >> t;
	ll N;
	while(t--)
	{
		cin >> N;
		ll ans = power2(N-1);
		ans = (ans - 2 + M)%M;
		// ans = max((ll)0, ans);
		if(N == 1)
			ans = 0;
		cout << ans << endl;
	}
	return 0;
}