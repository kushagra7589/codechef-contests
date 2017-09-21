#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	string a, b;
	while(t--)
	{
		cin >> a >> b;
		if(a.length() > 1e18 || b.length() > 1e18)
		{
			while(true);
		}

		ll sum=0;
        ll sum1=0;
        for(int i=0;i<a.length();i++)
        sum1+=(a[i]-'0');
        
        for(int i=0;i<b.length();i++)
        sum+=(b[i]-'0');
        
        cout<<((sum1%9)*(sum%9))%9<<endl;
	}
	return 0;
}