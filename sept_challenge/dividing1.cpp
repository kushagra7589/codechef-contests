#include <bits/stdc++.h>
#define LEFT(x) x<<2
#define RIGHT(x) x<<2|1
#define PARENT(x) x>>2
using namespace std;

const int MAX_SIZE = 1e6+10;
const int MAX_N = 1e5+10;

bool is_prime[MAX_SIZE];
// vector<int> prime_num;
int sp[MAX_SIZE];
int arr[MAX_N];
int seg[3*MAX_N][20];
int lazy[4*MAX_N];
vector<vector<int> > factors(MAX_SIZE);
int max_seg_tree = 0;

void build_tree(int v, int l, int r, int x)
{
	if(l == r)
	{
		seg[v][x] = factors[arr[l]][0];
		return;
	}
	int mid = (l+r)/2;
	build_tree(LEFT(v), l, mid);
	build_tree(RIGHT(v), mid+1, r);
	seg[v][x] = max(seg[LEFT(v)][x], seg[RIGHT(v)][x]);
}

void update(int v, int l, int r, int x, int y)
{

	if(l > y || r < x)
		return;
	if(x <= l && r <= y)
	{
		lazy[v] = max(max_seg_tree, lazy[v] + 1);
		seg[v][0] = seg[v][lazy[v]];
		if(l < r)
		{
			lazy[LEFT(v)] += 1;
			lazy[RIGHT(v)] += 1;
		}
		return;
	}
	int mid = (l+r)/2;
	update(LEFT(v), l, mid, x, y);
	update(RIGHT(v), mid+1, r, x, y);
	seg[v][0] = max(seg[LEFT(v)][0], seg[RIGHT(v)][0]);
}

int query(int v, int l, int r, int x, int y)
{
	seg[v][0] = seg[v][lazy[v]]
	
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
	// int t;
	for(int i=2; i<MAX_SIZE; i++)
	{
		is_prime[i] = true;
	}
	sieve(MAX_SIZE);
	for(int i=1; i<MAX_SIZE; i++)
	{
		get_factors(i);
	}
	build_tree(1, 1, n, 0);
	int i = 0;
	while(seg[0][i] != 1)
	{
		i++;
		build_tree(1,1,n, i);
	}
	max_seg_tree = i;
	return 0;
}