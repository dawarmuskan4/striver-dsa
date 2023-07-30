#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cout <<" Enter the string ";
  cin >> s;

  //hashing - pre computing 
  int hash[26] = {0}; //in case of lower case letters
  //int hash[256] = {0} in case of upper case letters
  for(int i=0; i<s.size(); i++){
    hash[s[i] -'a']++; 
  }

  cout << "Enter no of queries ";
  int q;
  cin >> q;

  cout << "Enter characters ";
  while(q--){
    char c;
    cin >> c;
    //hashing - fetch
    cout << hash[c-'a'] << endl;
  }

  return 0;
}