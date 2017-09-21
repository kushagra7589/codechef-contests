#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 2e5+10;

int arr[MAX_SIZE];
int first[MAX_SIZE];
int second[MAX_SIZE];

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < 2*n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + 2*n);
		for(int i = 0; i<n; i++)
		{
			first[i] = arr[i];
		}
		for(int i = n; i < 2*n; i++)
		{
			second[i - n] = arr[i];
		}
		cout << second[(n-1)/2] << endl;
		for(int i = 0; i < n; i++)
		{
			cout << first[i] << " " << second[i] << " ";
		}
		cout << endl;
	}
	return 0;
}