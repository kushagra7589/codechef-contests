#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<ll>

const int MAX_A = 1e5;
const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

vector<vector< ll > > factors(MAX_SIZE, vector<ll>());
vll input;
vll count(MAX_SIZE);
vll num(MAX_SIZE);

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


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		input.resize(n+1);
		for(int i=0; i<n; i++)
		{
			cin >> input[i];
			count[input[i]] += 1;
		}
	}
	return 0;
}