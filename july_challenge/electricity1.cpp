#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e5+10;
const long long INF = 2e9+1;
typedef long long ll;

vector<int> get_1_pos(string elec, ll *arr){
	vector<int> V;
	for(int i = 0; i<elec.length(); i++){
		if(elec[i] == '1'){
			V.push_back(i);
		}
	}
	return V;
}

ll get_min_dist(ll *arr, int l, int u){
	ll min_dist = INF;
	ll dist;
	// cout<<"l = "<<l<<" u = "<<u<<endl;
	for(int i=l; i<u; i++){
		dist = (arr[i] - arr[l]) + (arr[u] - arr[i+1]);
		cout<<"i = "<<i<<" dist = "<<dist<<endl;
		if(dist < min_dist)
			min_dist = dist;
	}
	// cout<<"MIN DIST = "<<min_dist<<endl;
	return min_dist;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	int n;
	ll arr[MAX_SIZE];
	string elec;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>elec;
		for(int i=0; i<n; i++)
			cin>>arr[i];
		vector<int> V = get_1_pos(elec, arr);
		ll ans = arr[V[0]] - arr[0];
		ans += arr[n-1] - arr[V[V.size()-1]];
		for(int i=0; i<V.size()-1; i++){
			int l = V[i];
			int u = V[i+1];
			ans += get_min_dist(arr, l, u);
		}
		cout<<ans<<endl;
	}
	return 0;
}