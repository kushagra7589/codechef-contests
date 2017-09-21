#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back

const int MAX_SIZE = 1e6+10;

vi v;
vi ans(MAX_SIZE);
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int input;
			cin >> input;
			v.pb(input);
		}
		sort(v.begin(), v.end());
		int counter = 0;
		for(int i=0; i<=(v.size()-1)/2; i++)
		{
			cout << v[i] << " ";
			ans[counter] = v[i];
			counter += 2;
		}
		counter = 1;
		for(int i=v.size() - 1; i>=v.size()/2; i--)
		{
			cout << v[i] << " ";
			ans[counter] = v[i];
			counter += 2;
		}
		cout << endl;
		for(int i=0; i<n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		ans.clear();
		v.clear();
	}
	return 0;
}