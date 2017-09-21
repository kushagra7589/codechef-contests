#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int a, b, c, w;
	cin>>a>>b>>c>>w;
	if(max((a+b), max((b+c), (a+c))) >= w)
		cout<<"YES";
	else
		cout<<"NO";
	cout<<endl;
	return 0;

}