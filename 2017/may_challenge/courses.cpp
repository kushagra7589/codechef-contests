#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int maxim = 0;
		int arr;
		for(int i = 0; i < n; i++) {
			cin >> arr;
			maxim = max(maxim, arr);
		}
		cout << n - maxim << endl;
	}
	return 0;
}