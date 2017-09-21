#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5;

int arr[2][MAX_SIZE];
int sum[2];
int start[2];
int finish[2];

set<int> fences;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		fences.clear();
		int n;
		cin >> n;
		string input;
		cin >> input;
		sum[0] = 0;
		sum[1] = 0;
		start[0] = start[1] = -1;
		finish[0] = finish[1] = -1;
		for(int i = 0; i < n; i++)
		{
			if(input[i] == '*')
			{
				if(start[0] == -1)
					start[0] = i;
				finish[0] = i;
				arr[0][i] = 1;
			}
			else
				arr[0][i] = 0;
			sum[0] += arr[0][i];
		}
		cin >> input;
		for(int i = 0; i < n; i++)
		{
			if(input[i] == '*')
			{
				if(start[1] == -1)
					start[1] = i;
				finish[1] = i;
				arr[1][i] = 1;
			}
			else
				arr[1][i] = 0;
			sum[1] += arr[1][i];
		}
		int ans = 0;
		if(sum[0] > 0 && sum[1] > 0)
		{
			ans += 1;
		}
		// cout << "Start 0 : ";
		// cout << start[0] << " " << finish[0] << endl;
		for(int i = start[0] + 1; i <= finish[0]; i++)
		{
			if(arr[0][i] == 1)
				fences.insert(i);
		}
		for(int i = start[1] + 1; i <= finish[1]; i++)
		{
			if(arr[1][i] == 1)
				fences.insert(i);
		}
		// for(auto &i : fences)
		// 	cout << i << " ";
		// cout << endl;
		// cout << "Anwser = ";
		cout << fences.size() + ans << endl;
	}
	return 0;
}