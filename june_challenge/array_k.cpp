#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int MAX_SIZE = 1e5 + 10;

typedef long long ll;

ll pow1(ll a, ll x){
	ll result = 1;
	while(x > 0){
		if(x&1){
			result = (result * a) % M;
		}
		x = x >> 1;
		a = (a*a)%M;
	}
	return result;
}

ll arr[MAX_SIZE/2] = {1};

ll min(ll a, ll b){
	return (a<b)?a:b;
}

void ncr(int n){
	for(int i = 1; i<=n/2; i++){
		arr[i] = (arr[i-1] * (n-i+1))%M;
		arr[i] = (pow1(i, M-2)*arr[i])%M;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int input;
	int n, k;
	while(t--){
		cin>>n>>k;
		ll N = n;
		ll R = k;
		for(int i = 0; i<n; i++){
			cin>>input;
			if(input == 0)
				N-=1;
		}
		ncr(N);
		ll ans = 0;
		if(N != n){
			for(int i = 0; i<=min(N, R); i++){
				int x = (i>N-i)?N-i:i;
				ans = (ans + arr[x])%M;
			}
		}
		else if(R % 2 == 0){
			for(int i = 0; i<=min(N, R); i+=2){
				int x = (i>N-i)?N-i:i;
				ans = (ans + arr[x])%M;
			}
			// ans = 0;
		}
		else{
			for(int i = 1; i<=min(N, R); i+=2){
				int x = (i>N-i)?N-i:i;
				ans = (ans + arr[x])%M;
			}
		}
		// if(ans == 0)
			// ans = 1;
		// if(ans == 0)
		// 	ans = 1;
		cout<<ans<<endl;
	}
	return 0;
}