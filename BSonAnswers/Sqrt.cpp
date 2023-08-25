#include<bits/stdc++.h>
using namespace std;

int brute(int n){
  int ans = 0;
  for(int i=1; i<=n; i++){
    if(i*i <= n){
      ans = i;
    }
    else break;
  }
  return ans;
}

int optimal1(int n){
  int low = 1;
  int high = n;
  int ans = 1;
  while(low <= high){
    long long mid = (low + high)/2;
    long long val = mid*mid;
    if(val <= n){
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

int main(){
  int a = 9;
  cout<< "Brute " << brute(a) << endl;
  cout << "Optimal " << optimal1(a);
}