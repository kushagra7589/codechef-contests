#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 3e5+10;

ll A[MAX_SIZE];
ll prefix_sum[MAX_SIZE];
ll B[210];

int main()
{
	ios_sync::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int N, M;
		cin >> N >> M;
		for(int i=0; i<N; i++)
		{
			cin >> A[i];
		}
		prefix_sum[0] = A[0];
		for(int i=1; i<N; i++)
		{
			prefix_sum[i] = prefix_sum[i-1] + A[i];
		}
		
	}
	return 0;
}