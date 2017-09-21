#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll sqrtN;
ll count1;

ld power(ld a, ll b)
{
	ld res = 1;
	while(b > 0)
	{
		if(b & 1)
			res = res*a;

		b = b >> 1;
		a = a*a;
	}
	return res;
}

bool bs(ld n, ll x)
{
	ll l = 1;
	ll u = 2*sqrtN;

	while(l < u)
	{
		ll mid = (l+u)/2;
		ld A = power(mid, x);
		if(A <= n)
			l = mid + 1;
		else u = mid;
	}

	ll one = l-1;

	l = 1;
	u = 2*sqrtN;

	while(l < u)
	{
		ll mid = (l + u)/2;
		ld A = power(mid, x);
		if(2 * A <= n)
			l = mid + 1;
		else
			u = mid;
	}

	ll two = l;

	count1 += one - two + 1;
	if(one == 2 && two == 2)
	{
		return false;
	}
	else if(one == 2)
	{
		count1 += 1;
		return false;
	}
	else if(one < 2)
		return false;
	else
		return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		ll N;
		cin >> N;
		sqrtN = sqrt(N);
		if(N == 0)
			cout << 0 << endl;
		else if(N == 1)
			cout << "INFINITY" << endl;
		else if(N == 2)
			cout << 1 << endl;
		else
		{
			count1 = N - N/2;
			int a = 2;
			while(true)
			{
				if(!bs(N, a))
					break;
				a++;
			}
			cout << count1 << endl;
		}
	}
	return 0;
}