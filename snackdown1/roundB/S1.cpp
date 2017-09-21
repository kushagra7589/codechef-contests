#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

const int MAX_SIZE = 1e5+10;

int arr[2][MAX_SIZE];
set< pair<int, int> > snakes;

bool done[2];
int last[2];
int sum[2] = {0};

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		sum[0] = sum[1] = 0;
		last[0] = last[1] = -1;
		int n;
		cin >> n;
		string input;
		cin >> input;
		for(int i = 0; i < n; i++)
		{
			if(input[i] == '*')
			{
				arr[0][i] = 1;
				snakes.insert(mp(i, 0));
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
				arr[1][i] = 1;
				snakes.insert(mp(i, 1));
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
		done[0] = done[1] = false;
		for(auto &i: snakes)
		{
			int index = i.second;
			// cout << i.second << " " << last[index] << endl;
			if(done[index])
			{
				// cout << i.first << " ";
				last[index] - i.first;
				ans += 1;
				if(last[1 - index] < i.first)
					done[1 - index] = false;
			}
			else
			{
				done[index] = true;
				last[index] = i.first;
			}
		}
		cout << ans << endl;
		snakes.clear();
	}
}