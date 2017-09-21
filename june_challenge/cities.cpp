#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

ll arr[MAX_SIZE];
ll R[MAX_SIZE];
double logR[MAX_SIZE];

ll F_prev, f_change;

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

void update(int p, int f, int n){
	ll x = pow1(arr[p], M-2);
	ll F = arr[p];
	int i;	
	if(p == 1){
		F_prev = F;
		f_change = f;
	}
	for(i = 1; i*i<(p-1); i++){
		if((p-1) % i == 0){
			R[i] = (R[i]*f)%M;
			R[i] = (R[i]*x)%M;
			R[(p-1)/i] = (R[(p-1)/i]*f)%M;
			R[(p-1)/i] = (R[(p-1)/i]*x)%M;
			logR[i] = (logR[i]+log10(f));
			logR[i] = logR[i]-log10(F);
			logR[(p-1)/i] = logR[(p-1)/i] + log10(f);
			logR[(p-1)/i] = logR[(p-1)/i] - log10(F);
		}
	}
	if(i*i == p-1){
		R[i] = (R[i]*f)%M;
		R[i] = (R[i]*x)%M;
		logR[i] = (logR[i]+log10(f));
		logR[i] = logR[i] - log10(F);
	}
	// if(p !?= 1)
	arr[p] = f;
}


int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++){
		cin>>arr[i];
	}
	for(int i = 1; i<=n; i++){
		R[i] = 1;
		logR[i] = 0;
		for(int j = 1; j<=n; j+=i){
			R[i] = (R[i]*arr[j])%M;
			logR[i] = logR[i] + log10(arr[j]);
			// logR[i] = logR[i] - int(logR[i]);
		}
	}
	F_prev = arr[1];
	f_change = arr[1];
	int q;
	cin>>q;
	int choice;
	int p, f, r;
	while(q--){
		cin>>choice;
		if(choice == 1){
			cin>>p>>f;
			update(p, f, n);
		}
		if(choice == 2){
			cin>>r;
			// cout<<R[r]<<endl;
			ll x = pow1(F_prev, M-2);
			R[r] = (R[r] * f_change)%M;
			R[r] = (R[r] * x)%M;
			logR[r] = logR[r] + log10(F_prev);
			logR[r] = logR[r] - log10(f_change);
			// F_prev = f_change;
			long double first = pow(10, logR[r] - int(logR[r]));
			if(ceil(first) - first < 1e-9)
				first = ceil(first);
			int ans = first;
			// printf("%.10lf %.15lf\n", logR[r]-int(logR[r]), first);
			cout<<ans<<" "<<R[r]<<endl;
		}
	}
	return 0;
}