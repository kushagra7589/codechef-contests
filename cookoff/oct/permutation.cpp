#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>

const int MAX_SIZE = 1e5+10;

vector<ll> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		arr.resize(n);
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int flag = 1;
		for(int i=1; i<n; i++)
		{
			if(arr[i] - arr[i-1] > 1)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		arr.clear();
	}
	return 0;
}