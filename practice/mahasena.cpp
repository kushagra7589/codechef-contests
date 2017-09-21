#include <bits/stdc++.h>

using namespace std;

int arr[2];

int main()
{
	int n;
	cin >> n; 
	int x;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		arr[x%2] += 1;
	}
	if(arr[0] > arr[1])
		cout << "READY FOR BATTLE" << endl;
	else
		cout << "NOT READY" << endl;
	return 0;
}