//Problem Code: CHEFELEC

#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;
typedef long long ll;

int search_city_with_coord(int *arr, int s, int l, int u){
	int mid;
	while(l < u){
		mid = l + (u-l)/2;
		// cout<<"u = "<<u<<" l = "<<l<<" mid = "<<mid<<endl;
		if(arr[mid] <= s){
			l = mid+1;
		}
		else{
			u  = mid;
		}
	}
	return l-1;
}

long long dist_btw_elec_cities(string elec, int *arr, int n, vector <int> const &V){
	ll dist = 0;
	dist += (ll)arr[V[0]] - arr[0];
	dist += (ll)arr[n-1] - arr[V[V.size()-1]];
	for(int i = 0; i<V.size()-1; i++){
		int pos = search_city_with_coord(arr, ((ll)arr[V[i]] + arr[V[i+1]])/2, V[i], V[i+1]);
		dist += (ll)arr[pos] - arr[V[i]];
		dist += (ll)arr[V[i+1]] - arr[pos+1]; 
	}
	return dist;
}

vector<int> get_1_pos(string elec, int *arr){
	vector<int> V;
	for(int i = 0; i<elec.length(); i++){
		if(elec[i] == '1'){
			V.push_back(i);
		}
	}
	return V;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	int n;
	string elec;
	int arr[MAX_SIZE];
	cin>>t;
	while(t--){
		cin>>n;
		cin>>elec;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<int> co_ord_1 = get_1_pos(elec, arr);
		long long ans = dist_btw_elec_cities(elec, arr, n, co_ord_1);
		cout<<ans<<endl;
	}
	return 0;
}