#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3 + 1;

// int search_item(int *arr, int l, int u, int s){
// 	int mid;
// 	while(l < u){
// 		mid = l + (u-l)/2;
// 		if(arr[mid] >= s){
// 			u = mid;
// 		}
// 		else{
// 			l = mid+1;
// 		}
// 	}
// 	return l;
// }

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	// scanf("%d", &t);
	int arr[MAX_SIZE];
	// int sorted[MAX_SIZE];
	int n;
	unordered_map<int, int> map1;
	// int check[MAX_SIZE] = {0};
	while(t--){
		cin>>n;
		// scanf("%d", &n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
			// scanf("%d", arr+i);
			// sorted[i] = arr[i];
			if(map1.find(arr[i]) == map1.end()){
				map1[arr[i]] = i;
				arr[i] = i;
			}
			else{
				arr[i] = map1[arr[i]];
			}
		}
		// sort(sorted, sorted+n);
		// for(int i=0; i<n; i++){
		// 	arr[i] = search_item(sorted, 0, n-1, arr[i]);
		// 	// cout<<arr[i]<<" ";
		// }
		// cout<<endl;
		long long count = 0;
		int i, j, k;
		int x;
		// long long count1;
		long long inter = 0;
		for(i=0; i<n; i++){
			int check[MAX_SIZE] = {};
			for(j=i; j<n; j++){
				
				// check[arr[j]] = 1;
				x = 0;
				// if(j != 0 && arr[j] == arr[j-1]){
				// 	// count = count*2;

				// }
				// else{
					// count1 = 0;
				if(check[arr[j]] != 1){
					check[arr[j]] = 1;
					inter = 0;
					for(k=j+1; k<n; k++){
						if(check[arr[k]] == 0){
							++x;
						}
						else{
							inter += (x*(x + 1))/2;
							x = 0;
						}
					}
					inter += (x*(x+1))/2;
				}
				count += inter;
				// }
				// count += count1;
			}
			// for(int y=0; y<n; y++){
			// 	// cout<<y<<":"<<check[y]<<" ";
			// 	check[y] = 0;
			// }
			// check[arr[i]] = 0;
			// cout<<endl;
		}
		cout<<count<<endl;
		// printf("%lld\n", count);
		map1.clear();
	}
	return 0;
}