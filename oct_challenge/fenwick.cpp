#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		string l1, l2, l3;
		ll n;
		cin >> l1 >> l2 >> l3 >> n;
		bool first = false;
		ll ans = 0;
		for(int i=l3.length()-1; i>=0; --i)
		{
			if(!first && l3[i] == '0')
				first = true;
			if(first && l3[i] == '1')
				ans += 1;
		}
		for(int i=l2.length()-1; i>=0; --i)
		{
			if(!first && l2[i] == '0')
				first = true;
			if(first && l2[i] == '1')
				ans += 1;
		}
		for(int i=l2.length()-1; i>=0; --i)
		{
			if(first && l2[i] == '1')
				ans += n-1;
		}
		for(int i=l1.length()-1; i>=0; --i)
		{
			if(!first && l1[i] == '0')
				first = true;
			if(first && l1[i] == '1')
				ans += 1;
		}
		ans += 1;
		cout << ans << endl ;
	}
}