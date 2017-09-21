#include <bits/stdc++.h>

using namespace std;

int n, m;

int check(int a, int b)
{
	if(a <= n && b <= m)
		return 1;
	else
		return 0;
}

int factors(int x)
{
	int ans = 0;
	int i;
	for(i=1; i*i < x; i++)
	{
		if(x % i == 0)
		{
			ans +=  check(i, x/i);
			ans += check(x/i, i);
		}
	}
	if(i*i == x)
	{
		ans += check(i, i);
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	int c;
	while(t--)
	{
		cin >> n >> m >> c;
		int res = factors(c);
		cout << res << endl;
	}
}