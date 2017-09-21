#include <bits/stdc++.h>
#define LEFT(x) x<<2
#define RIGHT(x) x<<2|1
#define PARENT(x) x>>2

using namespace std;

const int MAX_I = 1e6+10;
const int MAX_N = 1e5+10;

bool is_prime[MAX_I];
int sp[MAX_I];
vector< vector<int> > factors(MAX_I);
int arr[MAX_N];
int seg[MAX_N][20];
int lazy[MAX_N][2];

void build_tree(int x, int v, int l, int r)
{
	if(l == r)
	{
		seg[x][v] = factors[arr[l]][min(factors[arr[l]].size() - 1, x)];
		return;
	}
	int mid = (l+r)/2;
	build_tree(x, LEFT(v), l, mid);
	build_tree(x, RIGHT(v), mid+1, r);
	seg[x][v] = max(seg[x][LEFT(v)], seg[x][RIGHT(v)]);
}

void update(int v, int l, int r, int x, int y)
{
	if(lazy[1][v])
	{
		seg[0][v] = seg[lazy[0][v]][v];
		if(l < r)
		{
			lazy[0][LEFT(v)] += 1;
			lazy[0][RIGHT(v)] += 1;
		}
		lazy[1][v] = 0;
	}
	if(r < x || y < l)
		return;
	if(x <= l && r<=y)
	{
		lazy[0][v] += 1;
		seg[0][v] = seg[lazy[0][v]][v];
		if(l < r)
		{
			lazy[1][LEFT(v)] = 1;
			lazy[1][RIGHT(v)] = 1;
		}
		return;
	}	
	int mid = (l + r)/2;
	update(LEFT(v), l, mid, x, y);
	update(RIGHT(v), mid+1, r, x, y);
	seg[0][v] = max(seg[0]LEFT(v)], seg[0][RIGHT(v)]);
}

void mark_multiples(int a, int n)
{
	for(int i=a*a; i<n; i+=a)
	{
		is_prime[i] = false;
		sp[i] = a;
	}
}

void sieve(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(is_prime[i])
		{
			sp[i] = i;
			mark_multiples(i, n);
		}
	}
}

void get_factors(int x)
{
	int y = x;
	while(x > 1)
	{
		if(sp[x] == 0)
			sp[x] = x;
		factors[y].push_back(sp[x]);
		x /= sp[x];
	}
	factors[y].push_back(1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=2; i<MAX c_I; i++)
	{
		is_prime[i] = true;
	}
	int n, m, t, type, x, y;
	cin >> t;
	sieve(MAX_I);
	for(int i=1; i<MAX_I; i++)
	{
		get_factors(i);
	}
	while(t--)
	{

		cin >> n >> m;
		build_tree(0, 1, 1, n);
		int i=0;
	}
	return 0;
}