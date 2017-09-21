#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

ll arr[MAX_SIZE];
ll R[MAX_SIZE];
long double logR[MAX_SIZE];

ll pow1(ll a, ll b){
	ll result=1;
	while(b > 0){
		if(b&1){
			result = (result*a)%M;
		}
		b=b>>1;
		a=(a*a)%M;
	}
	return result;
}

void update(int p, ll f){
	if(p == 1){
		arr[p] = f;
		return;
	}
	ll x = pow1(arr[p], M-2);
	ll F = arr[p];
	p = p-1;
	int i = 1;
	for(i=1; i*i<p; i++){
		if(p%i == 0){
			int k = p/i;
			R[i] = (R[i]*x)%M;
			R[i] = (R[i]*f)%M;
			R[k] = (R[k]*x)%M;
			R[k] = (R[k]*f)%M;
			logR[i] = logR[i]-log10(F)+log10(f);
			logR[k] = logR[k]-log10(F)+log10(f);
		}
	}
	if(i*i == p){
		R[i] = (R[i]*x)%M;
		R[i] = (R[i]*f)%M;
		logR[i] = logR[i]-log10(F)+log10(f);
	}
	arr[p+1] = f;
}


int get_first(long double x){
	// cout<<x<<endl;
	long double A = pow(10, x);
	// cout<<A<<endl;
	x = x - ll(x);
	long double result = pow(10, x);
	if(ceil(result)-result < 1e-9)
		result = ceil(result);
	int ans = int(result);
	return ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll maxim = 0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		R[i] = 1;
		logR[i] = 0;
		if(arr[i] > maxim)
			maxim = arr[i];
	}
	for(int i = 1; i<=n; i++){
		// R[i] = 1;
		// logR[i] = 0;
		// cout<<"I = "<<i<<endl;
		for(int j = 1+i; j<=n; j+=i){
			// cout<<" J = "<<j;
			R[i] = (R[i]*arr[j])%M;
			// cout<<" log("<<arr[j]<<") = "<<log10(arr[j])<<endl;
			logR[i] = logR[i]+log10(arr[j]);
		}
		// cout<<"logR["<<i<<"] = "<<logR[i]<<endl;
	}
	int q;
	cin>>q;
	int choice;
	// if(n < 11 && q < 1001 && maxim < 10){
	// 	while(q--){
			
	// 	}
	// }
	else{
		while(q--){
			cin>>choice;
			if(choice == 1){
				int p;
				ll f;
				cin>>p>>f;
				update(p, f);
			}
			else if(choice == 2){
				int r;
				cin>>r;
				ll enj = (R[r]*arr[1])%M;
				// cout<<"logR["<<r<<"] = "<<logR[r]<<endl;
				int f_enj = get_first(logR[r] + log10(arr[1]));
				cout<<f_enj<<" "<<enj<<endl;
			}
		}
	}
	return 0;
}