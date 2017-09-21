#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e4 + 10;

int largest(int *a, int n){
	int max_index = 0;
	for(int i=1; i<n; i++){
		if(a[i] > a[max_index])
			max_index = i;
	}
	return max_index-1;
}

void make_zero(int *arr, int *base, int pos, int n){
	if(pos == n){
		if(base[pos] > base[pos-1]){
			base[pos-1] += arr[pos];
		}
		else{
			base[pos] += arr[pos];
		}
		return;
	}
	// cout<<"1. pos = "<<pos<<" B[pos] = "<<base[pos]<<endl;
	int x = largest(base + pos - 1, 3);
	// cout<<"2. largest index = "<<x<<" largest value = "<<base[x];
	if(x == -1){
		if(base[pos-1] < 0){
			base[pos-1] += arr[pos];
		}
		else{
			if(arr[pos+1] + base[pos] == 0){
				base[pos+1] += arr[pos];
			}
			else if(base[pos] + arr[pos+1] < 0){
				base[pos] += arr[pos]; 
			}
			else{
				if(base[pos] + arr[pos] > 0){
					base[pos+1] += arr[pos];
				}
				else{
					base[pos] += arr[pos];
 				}
			}
		}
	}
	else{
		base[pos-1]+= arr[pos]; 
	}
	// cout<<"\n3. pos = "<<pos<<" B[pos] = "<<base[pos]<<endl;
	make_zero(arr, base, pos+1, n);
}

void make_largest(int *arr, int *base, int pos, int n){
	if(pos == n){
		if(base[pos] > base[pos-1]){
			base[pos-1] += arr[pos];
		}
		else{
			base[pos] += arr[pos];
		}
		return;
	}
	int x = largest(base + pos - 1, 3);
	if(x == -1){
		if(base[pos-1] < 0)
			base[pos-1] += arr[pos];
		else{
			if(base[pos+1] + arr[pos] == base[pos] + arr[pos+1]){
				if(base[pos+2] + arr[pos+1] == base[pos+1] + arr[pos+2] && base[pos] + arr[pos] == base[pos+1] + arr[pos+2]){
					if(base[pos+2] + arr[pos+1] > base[pos+1] + arr[pos]){
						base[pos] += arr[pos];
					}
					else
						base[pos+1] += arr[pos];
				}
				else
					base[pos+1] += arr[pos];
			}
			else{
				base[pos] += arr[pos];
			}
		}
	}
	else{
		base[pos - 1] += arr[pos];
	}
	make_largest(arr, base, pos+1, n);
}

void take_input(int *A, int n){
	for(int i=1; i<= n; i++)
		cin>>A[i];
}

void get_min_max(int *arr, int *min, int *max, int n){
	for(int i = 2; i<=n; i++){
		if(arr[i] > arr[*max])
			*max = i;
		if(arr[i] < arr[*min])
			*min = i;
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
		int min=1, max=1;
		get_min_max(b, &min, &max, n);
		max = b[max];
		min = b[min];
		for(int i=1; i<=n; i++){
			b[i] -= max;
			c[i] = b[i];
		}
		b[n+1] = min - max;
		c[n+1] = b[n+1];
		make_zero(a, b, 1, n);
		int flag = 1;
		// cout<<"FINAL -> ";
		for(int i = 1; i<=n; i++){
			// cout<<b[i]<<" ";
			if(b[i] != 0){
				flag = 0;
				break;
			}
		}
		cout<<endl;
		if(flag){
			cout<<max<<endl;
		}
		else{
			// cout<<"FINAL 2 -> ";
			make_largest(a, c, 1, n);
			for(int i=2; i<=n; i++){
				// cout<<"i = "<<i<<" c[i] ="<<c[i]<<" ";
				if(c[i] != c[i-1]){
					flag = 1;
					break;
				}
			}
			// cout<<endl;
			if(flag)
				cout<<-1<<endl;
			else
				cout<<c[1]+max<<endl;
		}
	}
	return 0;
}