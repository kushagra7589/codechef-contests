#include <bits/stdc++.h>

using namespace std;

const int MAX_I = 1e5+10;
const int MAX_N = 1e6+10;

struct node{
	int count;
	int min_diff;
	int last_index;
	int flag;
};

int arr[MAX_N];
node Nodes[MAX_I];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<MAX_I; i++){
		Nodes[i].count = 0;
		Nodes[i].last_index = -1;
		Nodes[i].min_diff = MAX_N;
	}
	for(int i=0; i<n; i++){
		Nodes[arr[i]].count += 1;
		if(Nodes[arr[i]].last_index == -1)
			Nodes[arr[i]].last_index = i;
		else{
			if((i-Nodes[arr[i]].last_index+n)%n > Nodes[arr[i]].min_diff)
				Nodes[arr[i]].min_diff = (i-Nodes[arr[i]].last_index+n)%n;
			Nodes[arr[i]].last_index = i;
		}
	}
	for(int i=0; i<n; i++){
		if((i-Nodes[arr[i]].last_index+n)%n > Nodes[arr[i]].min_diff)
			Nodes[arr[i]].min_diff = (i-Nodes[arr[i]].last_index+n)%n;
		Nodes[arr[i]].last_index = i;
	}
	int minim = MAX_N;

	for(int i=0; i<10; i++){
		cout<<i<<endl;
		Nodes[i].min_diff = (Nodes[i].min_diff-1+n)%n;
		if(Nodes[i].min_diff < minim)
			minim = Nodes[i].min_diff;
		cout<<"COUNT = "<<Nodes[i].count<<" "<<"MINDIFF = "<<Nodes[i].min_diff<<endl;
	}
	cout<<minim<<endl;
	int ans = n + minim;
	cout<<ans<<endl; 	
	return 0;
}