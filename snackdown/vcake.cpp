#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// int check_div(int *r, int *c, int *arr){
// 	int flag = 0;
// 	for(int i=0; i<3; i++){
// 		if(arr[i] != 0){
// 			if(arr[i]%r == 0){
// 				flag += 1;
// 				c -= arr[i]/r;
// 				arr[i] = 0;
// 			}
// 		}
// 	}
// 	return flag;
// }

// int main(){
// 	ios_base::sync_with_stdio(false);
// 	int t;
// 	cin t;
// 	long long r, c, arr[3], arr1[3], r1, c1;
// 	int flag = 0;
// 	while(t--){
// 		// flag = 0;
// 		// while(arr[0] + arr[1] + arr[2] != 0 && count < 3){
// 		// 	for(int i=0; i<3; i++){
// 		// 		if(arr[i] != 0){
// 		// 			if(arr[i]%r == 0){
// 		// 				flag = 1;
// 		// 				c -= arr[i]/r;
// 		// 				arr[i] = 0;
// 		// 				break;
// 		// 			}
// 		// 		}
// 		// 	}
// 		// 	if(!flag){
// 		// 		swap(&r, &c);
// 		// 	}
// 		// 	count += 1;
// 		// }
// 		cin>>r>>c>>arr[0]>>arr[1]>>arr[2];
// 		// if(arr[0] % r == 0){
// 		// 	c -= arr[0]/r;
// 		// }
// 		r1 = r, c1 = c, arr1[0] = arr[0], arr1[1] = arr[1], arr1[2] = arr[2];
// 		int x = check_div(&r1, &c1, arr1);
// 		if(x == 0){
// 			x = check_div(&c, &r, arr);
// 			if(x == 0 || ){
// 				cout<<"No"<<endl;
// 			}
// 			else if(x == 1){

// 			}
// 		}
// 	}
// 	return 0;
// }

int check_div(int r, int c, vector <long long> &V, int *count){
	//base cases
	// cout<<"C = "<<c<<"R = "<<r<<endl;
	// for(std::vector<long long>::iterator it = V.begin(); it != V.end(); it++){
	// 	cout<<*it<<" ";
	// }
	// cout<<endl;
	if(*count == 2)
		return 0;
	if(V.empty()){
		if(c == 0)
			return 1;
		else
			return 0;
	}
	else{
		if(c <= 0)
			return 0;
	}
	int flag = 0;
	for(vector<long long>::iterator it = V.begin(); it != V.end(); it++){
		if((*it) % r == 0){
			flag = 1;
			c -= (*it)/r;
			V.erase(it);
			*count = 0;
			return check_div(r, c, V, count);
		}
	}
	if(!flag){
		*count += 1;
		return check_div(c, r, V, count);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	long long r, c, m, k, j;
	std::vector<long long> v;
	while(t--){
		cin>>r>>c>>m>>k>>j;
		v.push_back(m);
		v.push_back(k);
		v.push_back(j);
		int count = 0;
		int ans = check_div(r, c, v, &count);
		if(ans)
			cout<<"Yes"<<endl;
		else{
			v.clear();
			v.push_back(m);
			v.push_back(k);
			v.push_back(j);
			count = 0;
			ans = check_div(c, r, v, &count);
			if(ans)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}	
	return 0;
}