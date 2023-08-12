#include<bits/stdc++.h>
using namespace std;

//Longest subarray with sum K
//Brute approach - Generate all sub array by using 2 pointers i and j where
//i and j are pointing to the same element and then j keeps increasing and start
//suming the elements. check for the condition by comparing the sum and then length 
//TC- O(n^3)
//YOu can optimize the time complexity by removing the third loop and doing its functionality
//in the second loop itself.

int bruteGetLongestSubarray(int arr[], int k, int n){
  int len = 0;
  for(int i=0; i<n; i++){
    for(int j=i; j<n; j++){
      int sum = 0;
      for(int k=i; k<=j ; k++){
        sum += arr[k];
      }
      if(sum == k){
        len = max(len, j-i+1);
      }
    }
  }
  return len;
}

//Better approach - using HASHING  
// 

int main(){
  int n;
  cout << "enter arr size "; 
  cin >> n;

  cout << "Enter array element ";
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int k;
  cout << "Enter value of k ";
  cin >> k; 

  cout << bruteGetLongestSubarray(arr, k, n);
  return 0;
}