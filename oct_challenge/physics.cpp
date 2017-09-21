#include <bits/stdc++.h>

using namespace std;

#define ld long double

int main()
{
	// ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	ld s, v;
	while(t--)
	{
		cin >> s >> v;
		ld ans = (2*s)/(3*v);
		printf("%.7Lf\n", ans);
	}
	return 0;
}