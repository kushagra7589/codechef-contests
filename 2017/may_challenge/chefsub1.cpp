#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e5+10;

// const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

int A[N];
int arr[N];
int temp[N];

int main()
{
	ios_base::sync_with_stdio(false);
	int k, p;
	cin >> n >> k >> p;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 1; i < n; i++)
	{
		temp[i - 1] = A[i]; 
	}
	for(int i = 0; i < n; i++)
	{
		temp[i + n - 1] = A[i];
	}
	if(k > n)
		k = n;
	int L = n - k + 1;
	int start = n - 1;
	int size = 2*n- k;
	arr[0] = 0;
	for(int i = 0; i < k; i++)
	{
		arr[0] += temp[i];
	}
	for(int i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] - temp[i - 1] + temp[i + k - 1];
	}
	int prev_n = n;
	n = size;
	for(int i = 0; i < n; i++)
	{
		t[i + n] = arr[i];
	}
	build();
	string ques;
	cin >> ques;
	for(int i = 0; i < ques.length(); i++)
	{
		// cout << "start = " << start << endl;
		if(ques[i] == '?')
		{
			cout << query(start, start + L) << endl;
		}
		else
		{
			start = (start - 1 + prev_n) % prev_n;
		}
	}
	return 0;
}