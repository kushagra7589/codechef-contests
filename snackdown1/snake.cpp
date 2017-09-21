#include <bits/stdc++.h>

using namespace std;

int main()
{
	int R;
	cin >> R;
	int l;
	string report;
	while(R--)
	{
		cin >> l >> report;
		char prev = 'T';
		int flag = 0;
		for(int i = 0; i < l; i++)
		{
			if(report[i] != '.')
			{
				if(report[i] == prev)
				{
					flag = 1; break;
				}
				else
				{
					prev = report[i];
				}
			}
		}
		if(flag)
		{
			cout << "Invalid" << endl;
		}
		else
		{
			if(prev == 'H')
				cout << "Invalid" << endl;
			else
				cout << "Valid" << endl;
		}
	}
}