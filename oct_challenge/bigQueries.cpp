#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;
const int MAX_R = 1e3+10;
vector< pll > product(MAX_SIZE);
vector< pll > sdmp(MAX_R, mp(0, 0));
vector< pll > lazyX(MAX_R, mp(0, 0));
vector< pair< int, pll > > lazyY(MAX_R, mp(-1, mp(0, 0)));
int R;
vector< pll > factorial(MAX_SIZE);



bool lazyCheck(pll const &p)
{
	if(p.F == 0 && p.S == 0)
		return false;
	return true;
}

bool lazyCheckY(int x)
{
	return x != -1;
}

ll EXP2(ll x)
{
	ll ans = 0;
	while((x%2) == 0 && x > 0)
	{
		ans += 1;
		x = x/2;
	}
	return ans;
}

ll EXP5(ll x)
{
	ll ans = 0;
	while(x % 5 == 0 && x > 0)
	{
		ans += 1;
		x /= 5;
	}
	return ans;
}

void make_factorial()
{
	factorial.pb(mp(0, 0));
	for(int i=1; i<MAX_SIZE; i++)
	{
		ll two = EXP2(i);
		ll five = EXP5(i);
		factorial[i].F = factorial[i-1].F + two;
		factorial[i].S = factorial[i-1].S + five;
	}
}

pll Funct(int i)
{
	return factorial[i];
}

pll Two5(ll x)
{
	pll ans;
	ans.F = EXP2(x);
	ans.S = EXP5(x);
	return ans;
}

int root(int n)
{
	int l = 1;
	int h = 1e3;
	while(l < h)
	{
		int mid = (l+h)/2;
		if(mid*mid <= n)
			l = mid + 1;
		else
			h = mid;
	}
	return l-1;
}

void decompose(int n)
{
	for(int i=0; i<n; i++)
	{
		sdmp[i/R].F += product[i].F;
		sdmp[i/R].S += product[i].S;
	}
}

void display(vector< pll > const &A, int n)
{
	for(int i=0; i<=n; i++)
	{
		cout << A[i].F << " " << A[i].S << endl;
	}
}


void update1(int l, int r, ll x, int n)
{
	pll add;
	add.F = EXP2(x);
	add.S = EXP5(x);
	int start = l/R + 1;
	int end = r/R ;
	for(int i = start; i<end; i++)
	{
		sdmp[i].F += add.F*R;
		sdmp[i].S += add.S*R;
		lazyX[i].F += add.F;
		lazyX[i].S += add.S;
	}
	if(lazyCheckY(lazyY[l/R].F))
	{
		for(int i=(l/R)*R, j=0; i<start*R; i++, j++)
		{
			pll Y = mp(Funct(lazyY[l/R].F + j).F - Funct(lazyY[l/R].F - 1 + j).F, Funct(lazyY[l/R].F + j).S - Funct(lazyY[l/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[l/R].S.F;
			product[i].S = Y.S + lazyY[l/R].S.S;
 		}
 		lazyY[l/R].F = -1;
	}

	if(lazyCheck(lazyX[l/R]))
	{
		for(int i=(l/R)*R; i<start*R; i++)
		{
			product[i].F += lazyX[l/R].F;
			product[i].S += lazyX[l/R].S;
 		}
 		lazyX[l/R] = mp(0, 0);
	}	

	for(int i=l; i<min(r+1, start*R); i++)
	{
		sdmp[i/R].F -= product[i].F;
		sdmp[i/R].S -= product[i].S;
 		product[i].F += add.F;
		product[i].S += add.S;
		sdmp[i/R].F += product[i].F;
		sdmp[i/R].S += product[i].S;
 	}

	if(lazyCheckY(lazyY[r/R].F))
	{
		for(int i=end*R, j=0; i<min(n, (end+1)*R); i++, j++)
		{
			pll Y = mp(Funct(lazyY[r/R].F + j).F - Funct(lazyY[r/R].F - 1 + j).F, Funct(lazyY[r/R].F + j).S - Funct(lazyY[r/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[r/R].S.F;
			product[i].S = Y.S + lazyY[r/R].S.S;
 		}
 		lazyY[r/R].F = -1;
	}

	if(lazyCheck(lazyX[r/R]))
	{
		for(int i=end*R; i<min(n, (end+1)*R); i++)
		{
			product[i].F += lazyX[r/R].F;
			product[i].S += lazyX[r/R].S;
 		}
 		lazyX[r/R] = mp(0, 0);
	}
	if(start != end + 1)
	{
		for(int i=end*R; i<=r; i++)
		{
			sdmp[i/R].F -= product[i].F;
			sdmp[i/R].S -= product[i].S;
	 		product[i].F += add.F;
			product[i].S += add.S;
			sdmp[i/R].F += product[i].F;
			sdmp[i/R].S += product[i].S;
		}
	}
}

void update2(int l, int r, ll y, int n)
{
	pll add;
	add.F = EXP2(y);
	add.S = EXP5(y);
	int start = l/R + 1;
	int end = r/R;
	for(int i=start; i<end; i++)
	{
		int x = (i*R) - l;
		pll Y = mp(Funct(x + R).F - Funct(x).F, Funct(x+R).S - Funct(x).S);
		sdmp[i].F = Y.F + add.F*R;
		sdmp[i].S = Y.S + add.S*R;
		lazyX[i] = mp(0, 0);
		lazyY[i] = mp(x+1, mp(add.F, add.S));
	}
	if(lazyCheckY(lazyY[l/R].F))
	{
		for(int i=(l/R)*R, j=0; i<start*R; i++, j++)
		{
			pll Y = mp(Funct(lazyY[l/R].F + j).F - Funct(lazyY[l/R].F - 1 + j).F, Funct(lazyY[l/R].F + j).S - Funct(lazyY[l/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[l/R].S.F;
			product[i].S = Y.S + lazyY[l/R].S.S;
 		}
 		lazyY[l/R].F = -1;
	}

	if(lazyCheck(lazyX[l/R]))
	{
		for(int i=(l/R)*R; i<start*R; i++)
		{
			product[i].F += lazyX[l/R].F;
			product[i].S += lazyX[l/R].S;
 		}
 		lazyX[l/R] = mp(0, 0);
	}	

	for(int i=l; i<min(r+1, start*R); i++)
	{
		sdmp[i/R].F -= product[i].F;
		sdmp[i/R].S -= product[i].S;
		product[i].F = add.F + Funct(i-l+1).F - Funct(i-l).F;
		product[i].S = add.S + Funct(i-l+1).S - Funct(i-l).S;
		sdmp[i/R].F += product[i].F;
		sdmp[i/R].S += product[i].S;
	}

	if(lazyCheckY(lazyY[r/R].F))
	{
		for(int i=end*R, j=0; i<min(n, (end+1)*R); i++, j++)
		{
			pll Y = mp(Funct(lazyY[r/R].F + j).F - Funct(lazyY[r/R].F - 1 + j).F, Funct(lazyY[r/R].F + j).S - Funct(lazyY[r/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[r/R].S.F;
			product[i].S = Y.S + lazyY[r/R].S.S;
 		}
 		lazyY[r/R].F = -1;
	}

	if(lazyCheck(lazyX[r/R]))
	{
		for(int i=end*R; i<min(n, (end+1)*R); i++)
		{
			product[i].F += lazyX[r/R].F;
			product[i].S += lazyX[r/R].S;
 		}
 		lazyX[r/R] = mp(0, 0);
	}

	if(start != end +1)
	{
		for(int i=end*R; i<=r; i++)
		{
			sdmp[i/R].F -= product[i].F;
			sdmp[i/R].S -= product[i].S;
			product[i].F = add.F + Funct(i-l+1).F - Funct(i-l).F;
			product[i].S = add.S + Funct(i-l+1).S - Funct(i-l).S;
			sdmp[i/R].F += product[i].F;
			sdmp[i/R].S += product[i].S;
		}
	}


}

ll query(int l, int r, int n)
{
	pll ans = mp(0, 0);
	int start = l/R + 1;
	int end = r/R;
	for(int i=start; i<end; i++)
	{
		ans.F += sdmp[i].F;
		ans.S += sdmp[i].S;
	}
	if(lazyCheckY(lazyY[l/R].F))
	{
		for(int i=(l/R)*R, j=0; i<start*R; i++, j++)
		{
			pll Y = mp(Funct(lazyY[l/R].F + j).F - Funct(lazyY[l/R].F - 1 + j).F, Funct(lazyY[l/R].F + j).S - Funct(lazyY[l/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[l/R].S.F;
			product[i].S = Y.S + lazyY[l/R].S.S;
 		}
 		lazyY[l/R].F = -1;
	}

	if(lazyCheck(lazyX[l/R]))
	{
		for(int i=(l/R)*R; i<start*R; i++)
		{
			product[i].F += lazyX[l/R].F;
			product[i].S += lazyX[l/R].S;
 		}
 		lazyX[l/R] = mp(0, 0);
	}	

	for(int i=l; i<min(r+1, start*R); i++)
	{
		ans.F += product[i].F;
		ans.S += product[i].S;
	}

	if(lazyCheckY(lazyY[r/R].F))
	{
		for(int i=end*R, j=0; i<min(n, (end+1)*R); i++, j++)
		{
			pll Y = mp(Funct(lazyY[r/R].F + j).F - Funct(lazyY[r/R].F - 1 + j).F, Funct(lazyY[r/R].F + j).S - Funct(lazyY[r/R].F - 1 + j).S);
			product[i].F = Y.F + lazyY[r/R].S.F;
			product[i].S = Y.S + lazyY[r/R].S.S;
 		}
 		lazyY[r/R].F = -1;
	}

	if(lazyCheck(lazyX[r/R]))
	{
		for(int i=end*R; i<min(n, (end+1)*R); i++)
		{
			product[i].F += lazyX[r/R].F;
			product[i].S += lazyX[r/R].S;
 		}
 		lazyX[r/R] = mp(0, 0);
	}
	if(start != end +1)
	{
		for(int i=end*R; i<=r; i++)
		{
			ans.F += product[i].F;
			ans.S += product[i].S;
		}
	}
	return min(ans.F, ans.S);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	make_factorial();
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		ll x;
		R = root(n);
		for(int i=0; i<n; i++)
		{
			cin >> x;
			product[i] = Two5(x);
		}
		decompose(n);
		int type, l, r;
		ll y;
		ll sum = 0;
		while(m--)
		{
			cin >> type >> l >> r;
			if(type == 1)
			{
				cin >> y;
				update1(l-1, r-1, y, n);
			}
			else if(type == 2)
			{
				cin >> y;
				update2(l-1, r-1, y, n);
			}
			else
			{
				ll ans = query(l-1, r-1, n);
				sum += ans;
			}
		}
		cout << sum << endl;
		for(int i=0; i<=R; i++)
		{
			lazyX[i] = mp(0, 0);
			sdmp[i] = mp(0, 0);
			lazyY[i] = mp(-1, mp(0, 0));
		}
		for(int i=0; i<=n; i++)
		{
			product[i] = mp(0, 0);
		}
	}
}