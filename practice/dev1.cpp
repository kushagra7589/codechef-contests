#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int MAX_SIZE = 1e5+2;
const ll M = 1e9+7;

vector< vector< ll > > factors(MAX_SIZE, vector<ll>());
set< ll > input;
vector< ll > num(MAX_SIZE, 0);
vector< ll > subsets(MAX_SIZE, 0);
void makeFactors()
{
	for(int i = 2; i < MAX_SIZE; i++)
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

ll getProdGCD()
{
	ll prod  = 1;
	for(auto i : input)
	{
		ll sum = 0;
		for(auto j : factors[i])
		{
			sum += num[j];
		}
		ll exp = pow1(2, sum, M-1);
		subsets[i] += exp;
	}
	return prod;
}

void display(int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		for(auto j : factors[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	makeFactors();
	display(101);
	while(t--)
	{
		int n;
		cin >> n;
		ll temp;
		for(int i=0; i<n; i++)
		{
			cin >> temp;
			input.insert(temp);
			num[temp] += 1;
		}
		ll ans  = getProdGCD();
		cout << ans << endl;
	}
	return 0;
}