#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_SIZE = 2e5+10;
const int K = 17;
const int ZERO = 0; //create a max-sparse table.

ll arr[MAX_SIZE];
ll Table[MAX_SIZE][K+1];

void buildTable(int n, int k)
{
	for(int i=0; i<n; i++)
		Table[i][0] = arr[i];
	for(int j=1; j<=k; j++)
	{
		for(int i=0; i <= n-(1<<j); i++)
			Table[i][j] = max(Table[i][j-1], Table[i + (1 << (j-1))][j-1]);
	}
}

ll query(int l, int r, int k)
{
	ll answer = ZERO;
	for(int j=k; j>=0; j--)
	{
		if(l + (1<<j) - 1 <= r)
			answer = max(answer, Table[l][j]);
		l += (1 << j);
	}
	return answer;
}

int A[MAX_SIZE];
int temp[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, p;
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
	for(int i = 0; i < 2*n; i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	buildTable(size);
	string ques;
	cin >> ques;
	for(int i = 0; i < ques.length(); i++)
	{
		if(ques[i] == '?')
		{
			cout << query(start, start + L - 1) << endl;
		}
		else
		{
			start = (start - 1 + n) % n;
		}
	}
	return 0;
}