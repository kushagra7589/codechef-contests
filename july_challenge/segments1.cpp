#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE =  1e3 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	int A[MAX_SIZE];
	unordered_map<int, int> map1;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		int i, j, k, l;
		long long count = 0;
		int x;
		for(i=0; i<n-1; i++){
			for(j=i; j<n-1; j++){
				map1[A[j]] = 1;
				x = 0;
				for(k=j+1; k<n; k++){
					if(map1.find(A[k]) == map1.end()){
						x++;
					}
					else{
						count += (x*(x + 1))/2;
						x = 0;
					}
				}
				count += (x*(x+1)/2);
			}
			map1.clear();
		}
		cout<<count<<endl;
	}
	return 0;
}