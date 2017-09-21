#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e4 + 10;

void make_zero(int *a, int *b, int n){
	if(a[1]+b[0] < 0){
		b[0] += a[0];
	}
	else if(a[1] + b[0] == 0){
		b[1] += a[0];
	}
	else{
		if(a[0]+b[0] > 0){
			b[1] += a[0];
		}
		else{
			b[0] += a[0];
		}
	}
	for(int i=1; i<n-1; i++){
		if(b[i-1] < 0){
			b[i-1] += b[i];
		}
		else if(b[i] > b[i-1] || b[i+1] > b[i-1]){
			b[i-1] += a[i];
		}
		else if(a[i+1] + b[i] < 0){
			b[i] += a[i];
		}
		else if(a[i+1] + b[i] == 0){
			b[i+1] += a[i];
		}
		else{
			if(a[i] + b[i] > 0){
				b[i+1] += a[i];
			}
			else{
				b[i] += a[i];
			}
		}
	}
	if(b[n-1] < b[n-2]){
		b[n-1] += a[n-1];
	}
	else{
		b[n-2] += a[n-1];
	}
}

void make_equal(int *a, int *b, int n){
	if(b[1] + a[0] == b[0] + a[1]){
		b[1] += a[0];
	}
	else{
		b[0] += a[0];
	}
	for(int i=1; i<n-1; i++){
		if(b[i-1] < 0){
			b[i-1] += a[0];
		}
		else if(b[i]>b[i-1] || b[i+1]>b[i-1]){
			b[i-1] += a[0];
		}
		else if(b[i+1]+a[i] == b[i] + a[i+1]){
			b[i+1] += a[i];
		}
		else{
			a[i] += b[i];
		}
	}
	if(b[n-1] < b[n-2]){
		b[n-1] += a[n-1];
	}
	else{
		b[n-2] += a[n-1];
	}
}

void take_input(int *A, int n){
	for(int i=0; i< n; i++)
		cin>>A[i];
}

void get_min_max(int *arr, int *min1, int *max1, int n){
	for(int i = 1; i<n; i++){
		if(arr[i] > arr[*max1])
			*max1 = i;
		if(arr[i] < arr[*min1])
			*min1 = i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	int a[MAX_SIZE] = {0};
	int b[MAX_SIZE] = {0};
	int c[MAX_SIZE] = {0};
	int n;
	while(t--){
		cin>>n;
		take_input(a, n);
		take_input(b, n);
		int min1=0, max1=0;
		get_min_max(b, &min1, &max1, n);
		max1 = b[max1];
		min1 = b[min1];
		for(int i=0; i<n; i++){
			b[i] -= max1;
			c[i] = b[i];
			cout<<b[i]<<" ";
		}
		b[n] = min1 - max1;
		c[n] = b[n];
		cout<<endl;
		make_zero(a, b, n);
		int flag = 1;
		for(int i=0; i<n; i++){
			if(b[i] != 0){
				flag = 0;
				break;
			}
		}
		if(flag){
			cout<<max1<<endl;
		}
		else{
			make_equal(a, c, n);
			cout<<c[0]<<" ";
			for(int i=1; i<n; i++){
				cout<<c[i]<<" ";
				if(c[i] != c[i-1]){
					flag = 1;
					break;
				}
			}
			cout<<endl;
			if(flag)
				cout<<-1<<endl;
			else
				cout<<c[0]+max1<<endl;
		}
	}
	return 0;
}