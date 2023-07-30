#include<bits/stdc++.h>
using namespace std;

//print names n times
void printName(int i, int n){
  if(i>n){
    return;
  }
  cout <<i << " Muskan"<<endl;
  printName(i+1, n);
}

//print linearly from 1 to n
void printCount(int i, int n){
  if(i>n) return;
  cout << i << " ";
  printCount(i+1, n);
}

//print n to 1
void printRevCount(int i, int n){
  if(i<1){
    return;
  }
  cout << i << " ";
  printRevCount(i-1, n);
}

//print linearly from 1 to n using backtracking
void printCountBT(int i, int n){
  if(i<1){
    return;
  }
  printCountBT(i-1, n);
  cout << i << " ";
}

//print n to 1 using backtracking
void printRevCountBT(int n, int i){
  if(n<i)
    return;

    else
    printRevCountBT(n,i+1);
    cout<<i<<" ";
}

//sumation of first n numbers
//using parameters
void printSum1(int i, int sum){
  if(i<1){
    cout << sum ;
    return;
  }
  printSum1(i-1, sum+i);
}
//using functions
int sum(int n){
  if(n==0) return 0;
  return n+sum(n-1);
}

//recursion using functions -O(n)
int fact(int n){
  if(n==0) return 1;
  return n*fact(n-1);
}

//reverse an array using variable l and r
void revArray(int l, int r, int arr[]){
  if(l>=r){
    return;
  } 
  swap(arr[l],arr[r]);
  revArray(l+1, r-1, arr);
}

//reverse array using single variable
void revArray1(int i, int n, int arr[]){
  if(i>=n/2) return;
  swap(arr[i], arr[n-i-1]);
  revArray1(i+1, n, arr);
}

//palindrome - a string on reversal reads the same
bool palindrome(int i, string &s){
  if(i>=s.size()/2) return true;
  if(s[i] != s[s.size()-i-1]) return false;
  return palindrome(i+1, s);
}

//fibonnaci number - tc - O(2^n)
int fib(int n){
  if(n<=1) return n;
  int last = fib(n-1);
  int slast= fib(n-2);
  return last + slast;
}

int main(){
  int n;
  cout << "Enter n " ;
  cin >> n;
  cout << fib(n);
  // string s="MADAM";
  // cout << palindrome(0,s);
  // int arr[n];
  // cout <<" Enter array elements " ;
  // for(int i=0; i<n; i++){
  //   cin >> arr[i];
  // }
  // revArray1(0, n, arr);
  // for(int i=0; i<n; i++){
  //   cout << arr[i] << " ";
  // }
  return 0;
}