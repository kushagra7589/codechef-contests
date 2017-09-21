#include <iostream>
#include <map>

using namespace std;

const int INF = 1e5 + 1;

map<char, int> first = { {'C', -1 }, {'E', INF + 1}, {'S', INF + 2} };
map<char, int> last  = { {'C', INF}, {'E', INF + 1}, {'S', INF + 2} };

void get_first(string A, char s)
{
	for(int i = 0; i < A.length(); i++) {
		if(A[i] == s){
			first[s] = i;
			break;
		}
	}
}

void get_last(string A, char s) 
{
	for(int i = A.length() - 1; i >= 0; i--) {
		if(A[i] == s)
		{
			last[s] = i;
			break;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	string inp;
	while(t--) {
		cin >> inp;
		first['C'] = -1;
		first['E'] = INF + 1;
		first['S'] = INF + 2;
		last['C'] = -1;
		last['E'] = -1;
		last['S'] = -1;
 		get_first(inp, 'C');
		get_first(inp, 'E');
		get_first(inp, 'S');
		get_last(inp, 'C');
		get_last(inp, 'E');
		get_last(inp, 'S');
		// cout << "first : " << first['C'] << " " << first['E'] << " " << first['S'] << endl;
		// cout << "last : " << last['C'] << " " << last['E'] << " " << last['S'] << endl;
  		if(first['E'] < last['C'] || first['S'] < last['E'] || first['S'] < last['C'])
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}