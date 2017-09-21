#include <bits/stdc++.h>

using namespace std;

int k_special(long long num){
	long long x = num;
	int k = 0;
	int flag[10] = {0};
	while(x>0){
		int digit = x%10;
		if(digit != 0){
			if(flag[digit] == 0){
				if(num % digit == 0){
					k++;
				}
				flag[digit] = 1;
			}
		}
		x=x/10;
	}
	return k;
}

int gcd(int a, int b){
	if(b>a){
		return gcd(b, a);
	}
	else{
		while(b > 0){
			int temp = a;
			a = b;
			b = temp%b;
		}
		return a;
	}
}

int lcm(int *arr, int n){
	int hcf = arr[0], prod = arr[0]; 
	for(int i=1; i<n; i++){
		hcf = gcd(hcf, arr[i]);
		prod = prod * arr[i];
	}
	int lcm = prod/hcf;
}



int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	long long l, r;
	int k;
	long long count = 0;
	while(t--){
		count = 0;
		cin>>l>>r>>k;
		for(long long i=l; i<=r; i++){
			int ans = k_special(i);
			if(ans >= k)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}