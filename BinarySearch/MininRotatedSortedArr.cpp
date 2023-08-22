/*
Find min in rrotated sorted array with unique elements 
*/

/*
Identify the sorted half 
The rotating point will have the min element.
The sorted half may or may not have the min element.
After identifying the sorted half, store the min element and eliminate it. 
Then search for the min element in the other half and update if any change.
*/

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr, int n){
  int low = 0, high = n-1;
  int ans = INT_MAX;
  while(low <= high){
    int mid = (low+high)/2;
    //left half is sorted
    if(arr[low]<=arr[mid]){
      ans = min(ans, arr[low]);
      low = mid+1;
    } //right half is sorted
    else {
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr= {4,5,6,1,2,3};
  int n = arr.size();
  cout << findMin(arr, n);
  return 0;
}