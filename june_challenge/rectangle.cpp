#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1010;

int arr[MAX_SIZE][MAX_SIZE];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	int q, a, b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		// vec
		vector< vector< pair<int, int> > > lis_max(n);
		for(int i=0;i<n; i++){
			multiset<int > block(arr[i], arr[i]+b);
			pair<int, int> temp;
			multiset<int >::iterator maxim = block.end();
			maxim--;
			temp.first = *maxim;
			// cout<<temp.first<<endl;

			int sum= 0;
			for(int k=0; k<b; k++){
				sum += temp.first-arr[i][k];
			}
			temp.second = sum;
			lis_max[i].push_back(temp);
			for(int j=b, k=1; j<m; j++, k++){
				multiset<int>::iterator del = block.find(arr[i][j-b]);
				block.erase(del);
				block.insert(arr[i][j]);
				multiset<int >::iterator maxim = block.end();
				maxim--;
				temp.first = *maxim;
				if(temp.first == lis_max[i][k-1].first){
					sum -= (temp.first-arr[i][j-b]);
					sum += temp.first-arr[i][j];
					temp.second = sum;
				}
				else{
					sum -= (lis_max[i][k-1].first-arr[i][j-b]);
					sum += (b-1)*(temp.first - lis_max[i][k-1].first);
					sum += temp.first-arr[i][j];
				}
				temp.second = sum;
				lis_max[i].push_back(temp);
			}
		}
		vector< vector< pair<int, int> > > max_max(m-b+1);
		for(int col = 0; col<m-b+1; col++){
			multiset<int> block;
			for(int row = 0; row<a; row++){
				block.insert(lis_max[row][col].first);
			}
			multiset<int>::iterator maxim=block.end();
			maxim--;
			pair<int, int> temp;
			temp.first = *maxim;
			int sum = 0;
			for(int row=0; row<a; row++){
				sum += (temp.first - lis_max[row][col].first)*b + lis_max[row][col].second;
			}
			temp.second = sum;
			max_max[col].push_back(temp);
			for(int row=a, k=1; row<n; row++, k++){
				multiset<int>::iterator del = block.find(lis_max[row-a][col].first);
				block.erase(del);
				block.insert(lis_max[row][col].first);
				maxim = block.end();
				maxim--;
				temp.first = *maxim;
				if(temp.first == max_max[col][k-1].first){
					sum -= lis_max[row-a][col].second;
					sum -= (temp.first - lis_max[row-a][col].first)*b;
					sum += lis_max[row][col].second + (temp.first - lis_max[row][col].first)*b;
				}
				else{
					sum -= lis_max[row-a][col].second;
					sum -= (max_max[col][k-1].first - lis_max[row-a][col].first)*b;
					sum += (temp.first - max_max[col][k-1].first)*(a-1)*b;
					sum += lis_max[row][col].second + (temp.first - lis_max[row][col].first)*b;
				}
				temp.second = sum;
				max_max[col].push_back(temp);
			}
		}
		vector< vector< pair<int, int> > >::iterator row;
		vector< pair<int, int> >::iterator col;
		for(row = lis_max.begin(); row != lis_max.end(); row++){
			for(col = row->begin(); col != row->end(); col++){
				cout<<(*col).first<<"&"<<(*col).second<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		int minim = 50000;
		for(row = max_max.begin(); row != max_max.end(); row++){
			for(col = row->begin(); col != row->end(); col++){
				cout<<(*col).first<<"&"<<(*col).second<<" ";
				if((*col).second < minim)
					minim = (*col).second;
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<minim<<endl;
	}
	return 0;
}