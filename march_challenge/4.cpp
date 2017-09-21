#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int swaps_reqd(vector<int> &A, int allowed)
{
	int res = 0;
	for(auto &j : A)
	{
		res += j / (allowed + 1);
	}
	return res;
}

int if_all_1(string &inp)
{
	int n = inp.length();
	string zero(n, '0');
	string one(n, '1');
	for(int i = 1; i < n; i += 2)
	{
		zero[i] = '1';
		one[i] = '0';
	}
	int d1 = 0, d2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(inp[i] != zero[i])
			d1 += 1;
		else if(inp[i] != one[i])
			d2 += 1;
	}
	return min(d1, d2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t, n, k;
	string inp;
	cin >> t;
	vector< int > cont;
	while(t--)
	{
		cont.clear();
		cin >> n >> k;
		cin >> inp;
		int i=0;
		while(i < n)
		{
			char comp = inp[i];
			int cnt = 0;
			while(i < n && inp[i] == comp)
			{
				cnt++; i++;
			}
			cont.pb(cnt);
		}
		// cout << if_all_1(inp) << endl;
		int l = 1;
		int h = n+1;
		while(l < h)
		{
			int mid = (l+h)/2;
			int r = (mid == 1) ? if_all_1(inp) : swaps_reqd(cont, mid);
			// cout << "l = " << l << " h = " << h << endl;
			// cout << "m = " << mid << " kitne daalne padenge = " << r << endl; 
			if(r > k)
			{
				l = mid + 1;
			}
			else
			{
				h = mid;
			}
		}
		cout << l << endl;
	}
	return 0;
}