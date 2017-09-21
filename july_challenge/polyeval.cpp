#include <bits/stdc++.h>

using namespace std;

const int M = 786433;
const int MAX_SIZE = 3e5;

typedef long long ll;

int eval_poly(int *arr, int n, int k){
	long long sum = 0;
	for(int i=n; i>0; i--){
		sum = (sum+arr[i])%M;
		sum = (sum*k)%M;
	}
	sum = (sum+arr[0])%M;
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int arr[MAX_SIZE];
	int q;
	for(int i=0; i<=n; i++){
		cin>>arr[i];
	}
	cin>>q;
	int k;
	while(q--){
		cin>>k;
		cout<<eval_poly(arr, n, k)<<endl;
	}
	return 0;
}