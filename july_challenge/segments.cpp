#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	int A[MAX_SIZE];
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		unordered_map<int, int> map1, map2;
		int i, j, k, l;
		i=0;
		long long count = 0;
		while(i<n){
			j = i;
			while(j < n){
				// if(map1.find(A[j]) == map1.end()){
				// 	map1[A[j]] = 1;
				// }
				// else{
				// 	// map1.clear();
				// 	break;
				// }
				map1[A[j]] = 1;
				k = j+1;
				while(k < n){
					l = k;
					while(l < n){
						if(map1.find(A[l]) == map1.end()){
							// map2[A[l]] = 1;
							count++;
							// cout<<"a = "<<i+1<<" b = "<<j+1<<"\tc = "<<k+1<<" d = "<<l+1<<endl;
						}
						else{
							// map2.clear();
							// l++;
							break;
						}
						// else if(map2.find(A[l]) != map2.end()){
						// 	break;
						// }
						l++;
					}
					// map2.clear();
					k++;
				}
				j++;
			}
			map1.clear();
			i++;
		}
		cout<<count<<endl;
	}
	return 0;
}