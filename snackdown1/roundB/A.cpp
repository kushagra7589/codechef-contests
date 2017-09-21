#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 110;

bool dead[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		string input;
		cin >> input;
		int n = input.length();
		memset(dead, false, sizeof(dead));
		int snakes = 0, mongoose = 0;
		for(int i = 0; i <  n; i++)
		{
			if(input[i] == 's')
				snakes++;
			else
				mongoose++;
		}
		for(int i = 0; i < n; i++)
		{
			if(input[i] == 'm')
			{
				
				if(i > 0 && input[i - 1] == 's' && !dead[i - 1])
				{
					dead[i - 1] = true;
					snakes--;
				}
				else if((i < n - 1) && input[i + 1] == 's' && !dead[i + 1])
				{
					dead[i + 1] = true;
					snakes--;
				}
			}
		}
		cout << snakes << " " << mongoose << endl;
		if(snakes < mongoose)
		{
			cout << "mongooses" << endl;
		}
		else if(snakes > mongoose)
		{
			cout << "snakes" << endl;
		}
		else
		{
			cout << "tie" << endl;
		}
	}
	return 0;
}