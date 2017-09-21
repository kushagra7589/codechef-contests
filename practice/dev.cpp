#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

ll arr[MAX_SIZE];
ll input[MAX_SIZE];
ll num[MAX_SIZE];

ll xp(ll base, ll pwr){
	ll k = base, ans = 1;
	while(pwr){
		if(pwr % 2){
			ans = (ans * k) % M;
		}
		pwr /= 2;
		k = (k * k) % M;
	}
	return ans % M;
}

ll giveAns(int n)
{
	for(int k=1; k<=n; k++)
	{
		int i = input[k];
		ll prev = arr[i];
		arr[i] = (arr[i] * i)%M;
		for(int j=2; j*j <= i; j++)
		{
			if(i % j == 0)
			{
				arr[i] = (arr[i]*arr[j])%M;
				int other = i/j;
				if(j != other)
					arr[i] = (arr[i]*arr[other])%M;
			}
		}
		arr[i] = (arr[i] * prev) % M;
	}
	ll prod = 1;
	for(int i=2; i<=MAX_SIZE-10; i++)
	{
		prod = (prod * arr[i])%M;
	}
	return prod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll t, n, temp;
	cin>>t;
	while(t--){
		for(int i = 1; i <= 100000; i++){
			num[i] = 0;
			arr[i] = 1;
		}
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>temp;
			input[i+1] = temp; 
			num[temp] += 1;
		}
		sort(input+1, input+n+1);
		ll ans  = giveAns(n);
		cout << ans << endl;
	}
	return 0;
}