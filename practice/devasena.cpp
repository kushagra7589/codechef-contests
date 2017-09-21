#include <bits/stdc++.h>
using namespace std;
long long big = 1000000007;
typedef long long ll;
ll arr[100002], hcf[100002];
/*
ll gcd(ll a, ll b){
	if(a < b){
		int t = b;
		b = a;
		a = b;
	}
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
*/
 
ll xp(ll base, ll pwr, ll m){
	ll k = base, ans = 1;
	while(pwr){
		if(pwr % 2){
			ans = (ans * k) % m;
		}
		pwr /= 2;
		k = (k * k) % m;
	}
	return ans;
}
ll prodgcd(){
	for(int i = 1; i <= 100000; i++){
		for(int j = 1; j*j <= i; j++){
			if(i % j == 0){
				hcf[j] = (hcf[j] * xp(2, arr[i], big-1)) % (big - 1);
				int otherFactor = i/j;
				if(otherFactor != j){
					hcf[otherFactor] = (hcf[otherFactor] * xp(2, arr[i], big -1)) % (big-1);
				}
			}
		}
		hcf[i] = xp(2, arr[i], big - 1) - 1;
	}
	ll prod = 1;
	for(int i = 1; i <= 100000; i++){
		prod = (prod * xp(i, hcf[i], big)) % big;
	}
	return prod;
}
 
 
int main(){
	ll t, n, temp;
	cin>>t;
	while(t--){
		for(int i = 1; i <= 100000; i++){
			arr[i] = hcf[i] = 0;
		}
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>temp;
			arr[temp]++;
		}
		ll ans = prodgcd();
		cout<<ans<<endl;
	}
	return 0;
}