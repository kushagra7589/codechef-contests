#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

#define mp make_pair
#define F first
#define S second

int alpha[26];

// set< pair< int, int > > f1;
map<int, set<pair< int, int > > > f2; 
const int INF = 1e9;
void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

int absolute(int a)
{
	return (a < 0)? -a : a; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<26; i++)
			alpha[i] = 0;
		string s1, s2;
		cin >> s1 >> s2;
		if(s1.length() < s2.length())
			swap(s1, s2);

		int n1 = s1.length();
		int n2 = s2.length();
		for(int i=0; i<s1.length(); i++)
		{
			int index = s1[i]-65;
			f2[index].insert(mp(absolute(i - (n1-i-1)), i));			
		}
		int ugliness = INF;
		for(int i=0; i<n2; i++)
		{
			int index = s2[i]-65;
			if(f2.find(index) != f2.end())
			{
				auto it = f2[index].begin();
				int pos = (*it).S;
				int temp = 0;
				temp = absolute(i - pos) + absolute(pos - (n2 - i - 1)) + absolute((n2 - i - 1) - (n1 - pos - 1)) + absolute((n1 - pos - 1) - i);
				ugliness = min(ugliness, temp);
			}
		}
		cout << ugliness << endl;
		f2.clear();
	}
	return 0;
}