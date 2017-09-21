#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

vector< vector<int> > graph(MAX_SIZE);

deque<int> queue;

void make_edge(int x, int y){
	graph[x].push_back(y);
}

void bfs


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int v, e;
	int x, y;
	while(t--){	
		cin>>v>>e;
		for(int i=0; i<e; i++){
			cin>>x>>y;
			make_edge(x, y);
		}
	}
	return 0;
}