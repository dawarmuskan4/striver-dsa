/*Search in Rotated Sorted Array
Take one element, take it to the front and shift rest
two cases: 
1. unique elements
2. not unique elements
*/

/*Brute force - linear search
O(N) tc*/

/*Optimal solution - binary search
Identify the sorted half -> left/right (checking if the first element < mid element)
if right is smaller than or equal to n then we have found our answer else repeat for other side of array 

*/

#include<bits/stdc++.h>
using namespace std;

int searchRotatedArr(vector<int> &arr,int n, int target){
  int low = 0; 
  int high = n-1;
  while(low<=high){
    int mid =(low+high)/2;
    if(arr[mid] == target) return mid;
    //left sorted 
    if(arr[low]<=arr[mid]){
      if(arr[low]<=target && target <= arr[mid]){
        high = mid -1;
      } else {
        low = mid+1;
      }
    } else{
      if(arr[mid]<=target && target <= arr[high]){
        low = mid+1;
      } else{
        high = mid - 1;
      }
    }
  }
  return -1;
} 

int main(){
  vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = searchRotatedArr(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
  return 0;
}