#include <bits/stdc++.h>
#define LEFT(i) i*2 + 1
#define RIGHT(i) i*2 + 2
#define PARENT(i) (i-1)>>1
using namespace std;

int const max_N = 1e7 + 10;
long long int seg[4*max_N];
long long int lazy[4*max_N];

void build_tree(int *A, int v, int l, int r){
	if( l == r){
		seg[v] = A[l];
	}
	else if(l<r){
		int mid = (l+r)/2;
		build_tree(A, LEFT(v), l, mid);
		build_tree(A, RIGHT(v), mid+1, r);
		seg[v] = seg[LEFT(v)] + seg[RIGHT(v)];
	}
}

void update(int v, int l, int r, int x, int y){
	if(lazy[v]){
		seg[v]+=lazy[v]*(r-l+1);
		if(l<r){
			lazy[LEFT(v)]+=lazy[v];
			lazy[RIGHT(v)]+=lazy[v];
		}
		lazy[v] = 0;
	}
	if(l <= x && x <= r){
		if(l==r){
			seg[v] += y;
		}
		else{
			int mid = (l+r)/2;
			update(LEFT(v), l, mid, x, y);
			update(RIGHT(v), mid+1, r, x, y);
			seg[v] = seg[LEFT(v)] + seg[RIGHT(v)];
		}
	}
}

long long int query(int v, int l, int r, int x, int y){
	if(lazy[v]){
		seg[v]+=lazy[v]*(r-l+1);
		if(l<r){
			lazy[LEFT(v)]+=lazy[v];
			lazy[RIGHT(v)]+=lazy[v];
		}
		lazy[v] = 0;
	}
	if(r<x || y<l)
		return 0;
	if(x <= l && r<=y)
		return seg[v];
	int mid = (l+r)/2;
	long long int sum_l = query(LEFT(v), l, mid, x, y);
	long long int sum_r = query(RIGHT(v), mid+1, r, x, y);
	return sum_r+sum_l;
}

void range_update(int v, int l, int r, int x, int y, int z)
{
	if(lazy[v]){
		seg[v] += lazy[v]*(r-l+1);
		if(l<r){
			lazy[LEFT(v)] += lazy[v];
			lazy[RIGHT(v)] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(r<x || y<l)
		return;
	if(x <= l && r<=y){
		seg[v] += (long long)z*(r-l+1);
		if(l<r){
			lazy[LEFT(v)] += z;
			lazy[RIGHT(v)] += z;
		}
		return;
	}
	int mid = (l+r)/2;
	range_update(LEFT(v), l, mid, x, y, z);
	range_update(RIGHT(v), mid+1, r, x, y, z);
	seg[v] = seg[LEFT(v)] + seg[RIGHT(v)];
}

int main()
{
	int t;
	scanf("%d", &t);
	int n, c;
		// int A[100000] = {0};
	while(t--){
		scanf("%d %d", &n, &c);
		for(int i = 0; i<4*n; i++){
			lazy[i] = 0;
			seg[i] = 0;
		}
		int inp, x, y, z;
		// build_tree(A, 0, 0, n-1);
		while(c--){
			scanf("%d", &inp);
			if(inp == 0){
				scanf("%d %d %d", &x, &y, &z);
				range_update(0, 0, n-1, x-1, y-1, z);
			}
			else if(inp == 1){
				scanf("%d %d", &x, &y);
				printf("%lld\n", query(0, 0, n-1, x-1, y-1));
			}
		}
	}
	return 0;
}