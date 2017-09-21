#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 35;

typedef long long ll;
typedef long double ld;

#define pb push_back

// ld arr[MAX_SIZE];
vector<ld> arr1;
vector<ld> arr2;

vector<ld> countK(ld k, vector<ld> const &A)
{
	vector<ld> make;
	int n = A.size();
	for(int i = 1; i < (1 << n); i++)
	{
		int x = i;
		ld sum = 0;
		int index = 0;
		while(x > 0)
		{
			if(x & 1)
			{
				sum += A[index];
			}
			x = x >> 1;
			index += 1;
		}
		if(sum <= k)
		{
			make.pb(sum);
		}
	}
	return make;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	arr1.resize(n/2);
	arr2.resize(n - n/2);
	ld a;
	ld K = log(k);
	for(int i = 0; i < n/2; i++)
	{
		cin >> a;
		arr1[i] = log(a);
	}
	for(int i = 0; i < n - n/2; i++)
	{
		cin >> a;
		arr2[i] = log(a);
	}
	// sort(arr, arr + n);
	ll count = 0;
	vector<ld> first = countK(K, arr1);
	vector<ld> second = countK(K, arr2);
	count += first.size() + second.size();
	sort(second.begin(), second.end());
	for(int i = 0; i < first.size(); i++)
	{
		ld search = K - first[i];
		auto found = upper_bound(second.begin(), second.end(), search);
		ll add = found - second.begin();
		count += add;
	}
	cout << count << endl;
	return 0;
}