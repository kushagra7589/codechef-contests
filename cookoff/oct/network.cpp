#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

set< pair<int, string > > first_posts;
set< int > special;
set< pair<int, string > > other_posts;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int s;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		special.insert(s);
	}

	int f, p;
	string post;
	while(m--)
	{
		cin >> f >> p >> post;
		if(special.find(f) == special.end())
		{
			other_posts.insert(mp((-1) * p, post));
		}
		else
		{
			first_posts.insert(mp((-1) * p, post));
		}
	}
	for(auto i : first_posts)
	{
		cout << i.S << endl;
	}
	for(auto i : other_posts)
	{
		cout << i.S << endl;
	}
}