#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 510;

int graph[MAX_SIZE][MAX_SIZE];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>graph[i][j];
		}
	}
	int m;
	cin>>m;
	int k, x;
	cin>>k>>x;
	return 0;
}

