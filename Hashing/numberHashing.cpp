#include<bits/stdc++.h>
using namespace std;

//number hashing  
int main(){
  int n;
  cout << "Enter size of array ";
  cin >> n;
  int arr[n];
  cout<< "Enter array elements ";
  for(int i =0; i< n; i++){
    cin >> arr[i];
  }

  //precompute
  int hash[13]={0};
  for(int i=0; i<n; i++){
    hash[arr[i]] += 1;
  }

  int q;
  cout << "Enter no of queries ";
  cin >> q;
  cout << "Enter numbers ";
  while(q--){
    int number;
    cin >> number;
    cout << hash[number] << endl;
  }

  return 0;
}