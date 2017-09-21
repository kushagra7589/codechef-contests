#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M = 1e9+7;

ll power(ll x, ll y)
{
    ll res = 1;     
 
    x = x % M;  
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % M;
	    y = y>>1;
        x = (x*x) % M;  
    }
    return res;
}

ll get_count(string a, int start, int end)
{
	if(end == start)
	{
		return (ll)('Z' - a[start]);
	}
	if(end <  start)
		return 0;
	if(a[start] == 'Z' && a[end] == 'Z')
	{
		return get_count(a, start+1, end-1);
	}
	else if(a[start] == 'Z')
	{
		return get_count(a, start+1, end);
	}
	else if(a[end] == 'Z')
	{
		return get_count(a, start,end-1);
	}
	else
	{
		// cout << end - start + 1 << endl;
		return ((((ll)('Z'-a[start]) * (power(26, end-start+1 - 2)))%M * ((ll)('Z' - a[end])) + 1)%M + (((ll)('Z'-a[start] + 1) * (power(26, end-start+1 - 2)))%M * ((ll)('Z' - a[end])))%M) %M - 1;;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	cout << get_count(input, 0, input.length()-1) <<  endl;
	return 0;
}