#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAX_CHILD = 26;

struct Node {
	Node *children[MAX_CHILD];
	bool finish;
	bool last;
	bool done;
};

Node *initialize(Node *x)
{
	x = (Node *)malloc(sizeof(Node));
	x->finish = false;
	x->last = false;
	x->done = false;
	for(int i = 0; i < MAX_CHILD; i++)
	{
		x->children[i] = NULL;
	}
	return x;
}

void addSite(Node *root, string &s)
{
	Node *x = root;
	for(int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 97;
		if(x->children[index] == NULL)
		{
			x->children[index] = initialize(x->children[index]);
		}
		x = x->children[index];
	}
	x->last = true;
}

void check(Node *root, string &s)
{
	Node *x = root;
	for(int i = 0; i < s.length(); i++)
	{
		int index = s[i] - 97;
		if(x->children[index] == NULL)
		{
			for(int j = 0; j < MAX_CHILD; j++)
			{
				if(x->children[j] != NULL && x->children[j]->done == false)
				{
					// cout << "traversing " << s[i] << ": making finish true." << endl;
					x->children[j]->finish = true;
				}
				else if(x->children[j] != NULL)
				{
					// cout << "traversing " << s[i] << " : already done." << endl;
				}
			}
			return;
		}
		else
		{
			for(int j = 0; j < MAX_CHILD; j++)
			{
				if(x->children[j] != NULL && x->children[j]->done == false && j != index)
				{
					// cout << "traversing " << s[i] << ": making finish true." << endl;
					x->children[j]->finish = true;
				}
				else if(x->children[j] != NULL)
				{
					// cout << "traversing " << s[i] << " : already done." << endl;
				}
			}
			x = x->children[index];
			// cout << "traversing " << s[i] << " : making done true" << endl;
			x->done = true;
			x->finish = false;
		}
	}
	for(int i = 0; i < MAX_CHILD; i++)
	{
		if(x->children[i] != NULL && x->children[i]->done == false)
		{
			// cout << "traversing " << s[i] << ": making finish true." << endl;		
			x->children[i]->finish = true;
		}
		else if(x->children[i] != NULL)
		{
			// cout << "traversing " << s[i] << " : already done." << endl;
		}
	}
}

vector<string> prefixes;

bool dfs(Node *x, string &pref)
{
	if(x->finish)
	{
		prefixes.pb(pref);
		return true;
	}
	if(x->last)
	{
		// cout << "found last at " << pref << endl;
		return false;
	}
	for(int i = 0; i < MAX_CHILD; i++)
	{
		if(x->children[i])
		{
			char add = i + 97;
			string a = string(1, add);
			string next = pref + a;
			bool c = dfs(x->children[i], next);
			if(!c)
				return false;
		}
	}
	return true;
}

vector<string> unbloced;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	char c;
	string site;
	Node *root = initialize(root);
	for(int i = 0; i < n; i++)
	{
		cin >> c >> site;
		if(c == '-')
		{
			addSite(root, site);
		}
		else
		{
			unbloced.pb(site);
		}
	}
	for(auto &i : unbloced)
	{
		check(root, i);
	}
	string x = "";
	bool ans = dfs(root, x);
	if(ans)
	{
		sort(prefixes.begin(), prefixes.end());
		cout << prefixes.size() << endl;
		for(auto &i : prefixes)
		{
			cout << i << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}