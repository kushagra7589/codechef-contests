#include <bits/stdc++.h>

using namespace std;

int gcd_2(int n){
	if(n & 1)
		return 1;
	else
		return 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	long long n, c;
	cin>>t;
	while(t--){
		cin>>n>>c;
		if(c <= n)
			cout<<"No"<<endl;
		else if((c*2)%n != 0)
			cout<<"No"<<endl;
		else if((c*2)/n - 2 - (n-1) < 0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}