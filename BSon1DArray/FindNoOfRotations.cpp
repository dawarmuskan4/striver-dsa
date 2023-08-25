/*Find out how many times array has been rotatedand array consists of 
unique elements. */

/*Brute force
First, we will declare an ‘ans’ and an ‘index’ variable initialized with 
a large number and -1 respectively.
Next, we will iterate through the array and compare each element with the 
variable called ‘ans’. Whenever we encounter an element ‘arr[i]’ that is 
smaller than ‘ans’, we will update ‘ans’ with the value of ‘arr[i]’ and 
also update the ‘index’ variable with the corresponding index value, ‘i’.
Finally, we will return ‘index’ as our answer.
*/

#include<bits/stdc++.h>
using namespace std;

int findRotations(vector<int> &arr){
  int n = arr.size();
  int low = 0, high = n-1;
  int ans = INT_MAX;
  int index = -1;
  while(low <= high){
    int mid = (low+high)/2;

    if(arr[low]<=arr[high]){
      if(arr[low]< ans){
        index = low;
        ans = arr[low];
      }
      break;
    }
    //left half is sorted
    if(arr[low]<=arr[mid]){
      if(arr[low]<ans){
        index = low;
        ans = arr[low];
      }
      low = mid+1;
    } //right half is sorted
    else {
      if(arr[mid]<ans){
        index = mid;
        ans = arr[mid];
      }
      high = mid - 1;
    }
  }
  return index;
}

int main(){
  vector<int> arr= {4,5,6,1,2,3};
  
  cout << findRotations(arr);
  return 0;
}