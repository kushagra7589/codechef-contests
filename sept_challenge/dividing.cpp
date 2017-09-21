#include <bits/stdc++.h>
#define LEFT(i) i*2
#define RIGHT(i) i*2+1
#define PARENT(i) i/2 
using namespace std;

const int MAX_SIZE = 1e5+10;
const int MAX_I = 1e6+10;
const int SQRT_N = 1e3+10;

bool if_prime[MAX_I];
vector<int> primes;
int arr[MAX_SIZE];
int seg[MAX_SIZE * 4];

void build_seg_tree(int v, int l, int r)
{
	if(l == r)
	{
		seg[v] = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build_seg_tree(LEFT(v), l, mid);
	build_seg_tree(RIGHT(v), mid+1, r);
	seg[v] = max(seg[LEFT(v)], seg[RIGHT(v)]);
}

void update(int l, int r)
{
	
}

void mark_multiples(int a, int n)
{
	for(int i=a*a; i<n; i+=a)
	{
		if_prime[i] = false;
	}
}

void sieve(int n)
{
	for(int i=2; i < n; i++)
	{
		if(if_prime[i] == true)
		{
			mark_multiples(i, n);
			primes.push_back(i);
		}
	}
}

vector< queue<int> > factors(MAX_I);

void get_factor(int a)
{
	int b = a;
	int flag = 0;
	// while(b > 1)
	// {
	for(unsigned int i=0; i < primes.size() && primes[i]*primes[i] <= b; i++)
	{
		while(b % primes[i] == 0)
		{
			flag = 1;
			b /= primes[i];
			factors[a].push(primes[i]);
		}
	}
	if(flag == 0)
	{
		factors[a].push(a);
	}
	// }
	factors[a].push(1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=2; i<SQRT_N; i++)
	{
		if_prime[i] = true;
	}
	sieve(SQRT_N);
	// for(vector<int>::iterator i = primes.begin(); i != primes.end(); i++)
	// {
	// 	cout << *i << " ";
	// }
	// cout << endl;
	for(int i=1; i<MAX_I; i++)
	{
		get_factor(i);
	}
	// for(int i=1; i<1000; i++)
	// {
	// 	cout << i ;
	// 	while(!factors[i].empty())
	// 	{
	// 		cout << "->" << factors[i].front();
	// 		factors[i].pop();
	// 	}
	// 	cout << endl;
	// }
	int t;
	cin >> t;
	int n, m, type, l, r;
	while(t--)
	{
		cin >> n >> m;
		for(int i=1; i<= n; i++)
		{
			cin >> arr[i];
		}
		while(m--)
		{
			cin >> type >> l >> r;
		}
		cout << endl;
	}
	return 0;
}