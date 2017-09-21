#include <bits/stdc++.h>

using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	string a;
	string b;
	while(t--){
		int same00=0, same11=0, diff01=0, diff10=0;
		cin>>a;
		cin>>b;
		for(int i = 0; i<a.length(); i++){
			if(a[i] == b[i]){
				if(a[i] == '1')
					same11+=1;
				else
					same00+=1;
			}
			else{
				if(a[i] == '1')
					diff10 += 1;
				else
					diff01 += 1;
			}
		}
		// cout<<diff10<<" "<<diff01<<" "<<same00<<" "<<same11<<endl;
		int small = min(diff10, diff01);
		diff01 -= small;
		diff10 -= small;
		same00 += small;
		same11 += small;
		// cout<<diff10<<" "<<diff01<<" "<<same00<<" "<<same11<<endl;
		int count = small;
		int flag = 0;
		if(diff01 > 0){
			if(same11 > 0){
				flag = 1;
				count += diff01;
			}
			else flag = 0;
		}
		else if(diff10 > 0){
			if(same00 > 0){
				flag = 1;
				count += diff10;
			}
			else flag = 0;
		}
		else flag = 1;

		if(flag){
			cout<<"Lucky Chef"<<endl<<count<<endl;
		}
		else
			cout<<"Unlucky Chef"<<endl;
	}
	return 0;
}