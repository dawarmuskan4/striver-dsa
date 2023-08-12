#include<bits/stdc++.h>
using namespace std;

/*Sort array containing only 0, 1, 2*/

/*Brute force 
array contains only 3 digits, 0 1 2, so by sorting the array, all elements will be
arranged in increasing order.
*/

/* 
Better solution => TC= O(2n) SC = O(1)
count no of 0 1 2 in the array y iterating over the loop 
then manually over write array elements using count variables

int count0 = 0, count1=0, count2=0;
for(int i=0; i<n; i++){
  if(a[i]==0) count0++;
  else if(a[i]==1) count1++;
  else count2++;
}
for(int i=0; i<count0 ; i++) a[i]=0;
for(int i=count0; i<count0+count1 ; i++) a[i]=1;
for(int i=count0+count1; i<n ; i++) a[i]=2;
*/

/*
Optimal solution => TC = O(n) sc-O(1)
Dutch National Flag Algorithm
The algo uses 3 pointer - low, mid, high
It revolves around 3 rules -
everything btwn [0, low-1] will be 0 extreme left 
everything btwn [low, mid-1] will be 1
everything btwn [high+1, n] will be 2 extreme right

*/

void sortArray(vector<int>& arr, int n)
{
  int low=0, mid=0, high=n-1;
  while(mid<=high){
      if(arr[mid] == 0){
          swap(arr[low], arr[mid]);
          low++;
          mid++;
      } 
      else if(arr[mid]==1){
          mid++;
      } else{
          swap(arr[mid], arr[high]);
          high--;
      }
  }
}

int main(){
  int n = 6;
  vector<int> arr = {0, 2, 1, 2, 0, 1};
  sortArray(arr, n);
  cout << "After sorting:" << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}