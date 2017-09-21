#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e3+10;

unordered_map<int, int> map1;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int n;
	int arr[MAX_SIZE];
	while(t--){
		map1.clear();
		vector<vector<int> > V(MAX_SIZE);
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(map1.find(arr[i]) == map1.end()){
				map1[arr[i]] = i;
				arr[i] = i;
				V[i].push_back(i);
				// V[i].push_back(i)
			}
			else{
				arr[i] = map1[arr[i]];
				V[arr[i]].push_back(i);
			}
		}
		// int counter = 0;
		// for(vector<vector<int> >::iterator it = V.begin(); it != V.end(); it++){
		// 	cout<<counter;
		// 	for(vector<int>::iterator jt = it->begin(); jt !=  it->end(); jt++){
		// 		cout<<"->"<<*jt;
		// 	}
		// 	cout<<endl;
		// 	counter++;
		// }
		long long count = 0;
		vector<int> coll;
		for(int i=0; i<n-1; i++){
			for(int j=i; j<n-1; j++){
				for(vector<int>::iterator it = V[arr[j]].begin(); it != V[arr[j]].end(); it++){
					if(*it >= j){
						coll.push_back(*it);
					}
				}
				coll.push_back(n);
				sort(coll.begin(), coll.end());
				vector<int>::iterator beg = coll.begin();
				beg++;
				for(vector<int>::iterator it = beg; it != coll.end(); it++){
					vector<int>::iterator prev = it;
					prev--;
					int x = (*it - *prev - 1);
					count += (x*(x+1))/2;
				}
			}
			coll.clear();
		}
		cout<<count<<endl;
	}
	return 0;
}