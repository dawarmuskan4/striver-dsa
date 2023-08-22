/*Peak element in array
Peak element  means the element should be greater than the left and 
right element.
arr[i-1]<arr[i]>arr[i+1]
arr=[1,2,3,4,5,6,7,8,5,1] => peak = 8
An array can have multiple peaks
arr=[1,2,1,3,5,6,4] => peak = 2,6 return any 1
arr=[1,2,3,4,5] in this example, the elements are linearly increasing, so 
we will assume -inf on the left and right and then compare, then peak=5
arr=[5,4,2,3,1] in this ex also, we assume -inf on both side and then compaare,
peak = 5
*/

/*Brute force
linear iteration for entire array
tc=O(n)
*/

/*Better - binary search

*/

#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr){
  int n= arr.size();
  for(int i=0; i<n; i++){
    if((i==0 || arr[i-1] < arr[i]) && (i==n-1 || arr[i]>arr[i+1])) 
    return arr[i]; 
  }
}

int better(vector<int> &arr){
  int n = arr.size();
  //for one sized arary
  if(n==1) return 0;

  //when fist element is the peak
  if(arr[0]>arr[1]) return 0;

  //when last elemet is the peak
  if(arr[n-1]>arr[n-2]) return n-1;

  //search for peak in the rest of the array
  int low = 1, high = n-2;
  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
    else if(arr[mid]>arr[mid-1]) low = mid+1;
    else if(arr[mid]>arr[mid+1]) high = mid-1;
    else low = mid+1;
  }
  return -1;
}

int main(){
  vector<int> arr={1,2,3,4,5,6,7,8,5,1};
  cout << "Brute "<< brute(arr) << endl;
  cout << "better "<< better(arr) << endl;
  return 0;
}