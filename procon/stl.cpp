#include <bits/stdc++.h>

using namespace std;

vector<string> V(10,"yo");
vector< vector<int> > Akarsha(10, vector<int>(10, 0));
// vector< vector<int> > Matrix(100, vector<int>(100, -1));
deque< vector<int> > Q;

void display(vector<vector<int> > &Akarsha){
    for(int i=0; i<Akarsha.size(); i++){
		for(int j=0; j<Akarsha[i].size(); j++){
	//		cout<<Akarsha[i][j]<<" ";
				Akarsha[i][j]=i+j;
			}
		//cout<<endl;
	}

	for(int i=0; i<Akarsha.size(); i++){
		for(int j=0; j<Akarsha[i].size(); j++){
			cout<<Akarsha[i][j]<<" ";
		}
		cout<<endl;
	}
}

// struct CompareVect{
// 	bool operator()(const vector<int> &V1, const vector<int> &V2){
// 		return V1[0] > V2[0];
// 	}
// };

int main(){
	// cout<<V.size()<<endl;
	int row = 0, col = 0;
	for(vector< vector<int> >:: iterator i = Akarsha.begin();i!=Akarsha.end();i++){
		col = 0;
		for(vector<int>:: iterator j = i->begin() ; j!=i->end() ; j++){
			cout<<*j<<" ";
			if(col==5 || col==3){
				Akarsha[row][col] = 10;
			}
			col++;
		}
		row++;
		cout<<endl;
	}
	display(Akarsha);
	for(int i=0; i<Akarsha.size(); i++){
		for(int j=0; j<Akarsha[i].size(); j++){
			cout<<Akarsha[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0; i<Akarsha.size(); i++){
		sort(Akarsha[i].begin(), Akarsha[i].end(), CompareVect);
	}
	/*for(vector< vector<int> >::iterator it = V.begin(); it != V.end(); it++){
		for (vector<>::iterator i = .begin(); i != .end(); ++i)
		{
			
		}
		cout<<*it<<endl;
	}*/

	return 0;
}