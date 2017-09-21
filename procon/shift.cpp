#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e6 + 10;

int arr[MAX_SIZE];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int equal = arr[0];
	int i=0;
	while(i < n && arr[i] == equal){
		i++;
	}
	int ans = i + 2*(n-i);
	cout<<ans<<endl;
	return 0;
}