#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e3+4;

int max(int a, int b){
	return (a>b)?a:b;
}

int seg_max[MAX_SIZE][4*MAX_SIZE]={{0}};
long long seg_sum[MAX_SIZE][4*MAX_SIZE]={{0}};

int seg_sub_sum[MAX_SIZE][4*MAX_SIZE]={{0}};
long long seg_sub_max[MAX_SIZE][4*MAX_SIZE]={{0}};

void  build_max_tree(int *arr, int v, int l, int r, int i){
	if(l == r)
		seg_max[i][v] = arr[l];
	else{
		int mid = (l+r)/2;
		build_max_tree(arr, 2*v, l, mid, i);
		build_max_tree(arr, 2*v+1, mid+1, r, i);
		seg_max[i][v] = max(seg_max[i][2*v], seg_max[i][2*v+1]);
	}
}

void  build_sub_max_tree(int *arr, int v, int l, int r, int i){
	if(l == r)
		seg_sub_max[i][v] = arr[l];
	else{
		int mid = (l+r)/2;
		build_sub_max_tree(arr, 2*v, l, mid, i);
		build_sub_max_tree(arr, 2*v+1, mid+1, r, i);
		seg_sub_max[i][v] = max(seg_sub_max[i][2*v], seg_sub_max[i][2*v+1]);
	}
}

void build_sum_tree(int *arr, int v, int l, int r, int i){
	if(l == r)
		seg_sum[i][v] = arr[l];
	else{
		int mid = (l+r)/2;
		build_sum_tree(arr, 2*v, l, mid, i);
		build_sum_tree(arr, 2*v+1, mid+1, r, i);
		seg_sum[i][v] = seg_sum[i][2*v] + seg_sum[i][2*v+1];
	}
}

void build_sub_sum_tree(long long *arr, int v, int l, int r, int i){
	if(l == r)
		seg_sub_sum[i][v] = arr[l];
	else{
		int mid = (l+r)/2;
		build_sub_sum_tree(arr, 2*v, l, mid, i);
		build_sub_sum_tree(arr, 2*v+1, mid+1, r, i);
		seg_sub_sum[i][v] = seg_sub_sum[i][2*v] +  seg_sub_sum[i][2*v+1];
	}
}


int query_sum(int v, int l, int r, int x, int y, int i){
	if(r < x || y < l)
		return 0;
	else if(x <= l && l<=r && r<=y)
		return seg_sum[i][v];
	else{
		int mid  = (l+r)/2;
		return query_sum(2*v, l, mid, x, y, i) + query_sum(2*v+1, mid+1, r, x, y, i);
	}
}

int query_sub_sum(int v, int l, int r, int x, int y, int i){
	if(r < x || y < l)
		return 0;
	else if(x <= l && l<=r && r<=y)
		return seg_sub_sum[i][v];
	else{
		int mid  = (l+r)/2;
		return query_sub_sum(2*v, l, mid, x, y, i) + query_sub_sum(2*v+1, mid+1, r, x, y, i);
	}
}

int query_max(int v, int l, int r, int x, int y, int i){
	if(r < x || y < l)
		return 0;
	else if(x <= l && l<=r && r<=y)
		return seg_max[i][v];
	else{
		int mid  = (l+r)/2;
		return max(query_max(2*v, l, mid, x, y, i), query_max(2*v+1, mid+1, r, x, y, i));
	}	
}

int query_sub_max(int v, int l, int r, int x, int y, int i){
	if(r < x || y < l)
		return 0;
	else if(x <= l && l<=r && r<=y)
		return seg_sub_max[i][v];
	else{
		int mid  = (l+r)/2;
		return max(query_sub_max(2*v, l, mid, x, y, i), query_sub_max(2*v+1, mid+1, r, x, y, i));
	}	
}

int input[MAX_SIZE][MAX_SIZE];
long long sum_arr[MAX_SIZE][MAX_SIZE];
int max_arr[MAX_SIZE][MAX_SIZE];

int min(int a, int b){
	return (a<b)?a:b;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	for(int  i = 1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>input[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		build_sum_tree(input[i], 1, 1, m, i);
		build_max_tree(input[i], 1, 1, m, i);
	}
	// for(int i=1; i<=4*m; i++){
	// 	cout<<seg_sum[1][i]<<" ";
	// }
	// cout<<endl;
	int q, a, b;
	cin>>q;
	while(q--){
		cin>>a>>b;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m-b+1; j++){
				sum_arr[j][i] = query_sum(1, 1, m, j, j+b-1, i);
				max_arr[j][i] = query_max(1, 1, m, j, j+b-1, i);
			}
			// cout<<endl;
		}
		// for(int i=1;i<=m-b+1;i++){
		// 	for(int j=1; j<=n; j++)
		// 		cout<<i<<","<<j<<":"<<sum_arr[i][j]<<"&"<<max_arr[i][j]<<" ";
		// 	cout<<endl;
		// }

		for(int i=1; i<=m-b+1; i++){
			build_sub_sum_tree(sum_arr[i], 1, 1, n, i);
			build_sub_max_tree(max_arr[i], 1, 1, n, i);
		}
		// for(int i=1; i<=4*n; i++){
		// 	cout<<seg_sub_max[1][i]<<" ";
		// }
		// cout<<endl;
		int minim = 1000000;
		long long sum, maxim;
		int res;
		for(int i=1; i<=m-b+1; i++){
			for(int j=1; j<=n-a+1; j++){
				sum = query_sub_sum(1, 1, n, j, j+a-1, i);
				maxim = query_sub_max(1, 1, n, j, j+a-1, i);
				res = (a*b)*maxim - sum;
				minim = min(minim, res);
				// cout<<sum<<"&"<<maxim<<"&"<<res<<" ";
			}
			// cout<<endl;
		}
		cout<<minim<<endl;
	}
	return 0;
}