#include <iostream>

using namespace std;

int check_prime(int n){
	for(int i=2; i<n; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int t;
	cin>>t;
	int n;
	for(int i=0; i<t; i++){
		cin>>n;
		int ans = check_prime(n);
		if(ans == 0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}