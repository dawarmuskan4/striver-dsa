#include<bits/stdc++.h>
using namespace std;

int power(int n, int p){
  if (p == 0) return 1;
  int ans = 1;
  for(int i=1; i<=p; i++){
    ans *= n;
  }
  return ans;
}

int brute(int n, int m){
  for(int i=1; i<=n; i++){
    long long val = power(i, n);
    if(val == m) return i;
    else if(val > m) break;
  }
  return -1;
}

int func(int mid, int n){
  long long ans = 1;
  while(n > 0){
    if(n % 2==0){
      ans = ans * mid;
      n = n-1;
    } else {
      mid = mid*mid;
      n = n/2;
    }
  }
  return ans;
}

int optimal(int n , int m){
  int low= 1, high = m;
  while (low<=high){
    int mid = (low+high)/2;
    int midN = func(mid, n);
    if(midN == 0) return mid;
    else if(midN < m) low = mid + 1;
    else high = mid -1 ;
  }
  return -1;
}

int main(){
  cout << brute(4,256);
  return 0;
}