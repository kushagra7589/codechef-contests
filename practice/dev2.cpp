#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int MAX_A = 1e5;
const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

vector< vector < ll > >  factors(MAX_SIZE, vector<ll>());
vector< ll > input;
vector< ll > num(MAX_SIZE, 0);

ll pow1(ll a, ll b, ll m)
{
	ll k = a;
	ll ans = 1;
	while(b)
	{
		if(b % 2)
		{
			ans = (ans * k) % m;
		}
		k = (k*k)%m;
		b /= 2;
	}
	return ans;
}

void makeFactors()
{
	for(int i=2; i<=MAX_A; i++)
	{
		for(int j=2; j*j <= i; j++)
		{
			if(i % j == 0)
			{
				factors[i].pb(j);
				if(i/j != j)
					factors[i].pb(i/j);
			}
		}
		factors[i].pb(i);
	}
}

ll getProdGCD()
{
	for(auto i : input)
	{
		for(auto factor : factors[i])
		{
			num[factor] += 1;
		}
		num[i] -= 1;
	}
	ll prod = 1;
	for(auto i : input)
	{
		// if(num[i] != 0)
		// {
			cout << i << " : " << num[i] <<  endl;
			ll inter = (pow1(2, num[i], M-1)) % M;
			prod = (prod * pow1(i, inter, M))%M;
		// }
	}
	return prod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	makeFactors();
	while(t--)
	{
		for(int i=0; i<=MAX_A; i++)
			num[i] = 0;
		int n;
		cin >> n;
		input.resize(n);
		// ll temp;
		for(int i=0; i<n; i++)
		{
			cin >> input[i];
		}
		sort(input.begin(), input.end());
		ll ans  = getProdGCD();
		cout << ans << endl;

	}
}