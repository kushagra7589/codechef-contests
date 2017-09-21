#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e6 + 10;
const int MAX_I = 1e5+10;

int arr[MAX_SIZE];

vector< vector<int> > V(MAX_I);

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		V[arr[i]].push_back(i);
	}
	int maxim = 0;
	int inter;
	int min_diff = MAX_SIZE;
	int diff;

	for(int i=0; i<10; i++){
		cout<<i;
		if(!V[i].empty()){
			for(int j=0; j<V[i].size(); j++){
				cout<<"->"<<V[i][j];
			}
		}
		cout<<endl;
	}
	int j=0;
	for(vector< vector<int> >::iterator it=V.begin(); it != V.end(); it++){
		cout<<j<<endl;
		min_diff = MAX_SIZE;
		if(!(it->empty())){
			inter += it->size();
			cout<<inter<<" ";
			for(int i=0; i<it->size()-1; i++){
				diff = (*it)[(i+1)%n] - (*it)[(i)%n];
				if(diff > min_diff)
					min_diff = diff;
			}
			inter += min_diff;
			cout<<inter<<endl;
			if(inter > maxim)
				maxim = inter;
		}
		j++;
		if(j==5)
			break;
	}
	cout<<maxim<<endl;
	int ans = 2*n - maxim;
	cout<<ans<<endl;
	return 0;
}