#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout << "Enter n ";
  cin >> n;

  int arr[n];
  cout << "Enter array elements ";
  for(int i = 0; i< n; i++){
    cin >> arr[i];
  }

  //hashing - precompute
  unordered_map<int ,int> mpp; // for number hashing
  //map <char, int>  for character  hashing
  for(int i = 0; i<n; i++){
    mpp[arr[i]]++;
  }

//iterating map values
  for(auto it: mpp){
    cout << it.first << "->" << it.second << endl;
  }

  int q;
  cout << "Enter no of queries ";
  cin >> q;
  cout << "Enter numbers ";
  while(q--){
    int number;
    cin >> number;
    //hashing -fetch 
    cout << mpp[number] << " ";
  }
  return 0;
}