#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int sum = 0;
    string hey;
    cin >> hey;
    for(int i = 0; i < hey.length(); i++){
      if(hey[i]-48 > 0  && hey[i] - 48 < 10){
        sum += hey[i] - 48;
      }
    }
    cout << sum << endl;
  }
  return 0;
}