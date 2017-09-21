//Problem Code: CHEFARC

#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 110;

bool arr[MAX_SIZE][MAX_SIZE];
set< pair<int, int> > V1;
// set< pair<int, int> > V2;

set< pair<int, int> > make_addends(int sum){
	set< pair<int, int> > V;
	for(int i=0; i<=sum/2; i++){
		pair<int, int> P;
		P.first = i;
		P.second = sum-i;
		V.insert(P);
		P.first = sum-i;
		P.second = i;
		V.insert(P);
	}
	return V;
}

void add_edge(vector< list< int> > &graph, int x, int y){
	graph[x].push_front(y);
}
int convert_to_1d(int i, int j, int m){
	return i*m + j;
}

void make_graph(vector< list<int > > &graph, int k, int n, int m){
	V1 = make_addends(k);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == false){
				int index = convert_to_1d(i, j, m);
				for(set<pair<int, int> >::iterator it = V1.begin(); it != V1.end(); it++){
					// add_edge(graph, i + (*it).first, j + ())
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n, m, k1, k2;
	while(t--){
		cin>>n>>m>>k1>>k2;
		// V2 = make_addends(k2);
		for(int i = 0; i<n; i++){
			for(int j = 0; j < m; j++){
				cin>>arr[i][j];
			}
		}

	}
	return 0;
}