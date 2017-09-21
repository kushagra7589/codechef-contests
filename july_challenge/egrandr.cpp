#include <bits/stdc++.h>

using namespace std;

int arr[6] = {0};

int check_result(int n, int sum){
	double avg = (double)sum/n;
	if(arr[2] > 0)
		return -1;
	if(arr[5] == 0)
		return -1;
	if(avg < 4)
		return -1;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	int grade;
	while(t--){
		int sum = 0;
		for(int i=0; i<6; i++){
			arr[i] = 0;
		}
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>grade;
			arr[grade] += 1;
			sum += grade;
		}
		int ans = check_result(n, sum);
		if(ans == 1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}