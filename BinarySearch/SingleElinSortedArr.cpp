/*Find the single element in the sorted array
All the numbers in the array are appearing twice except for one element.
the array is sorted. 
*/

/*Brute force
the element which is appearing twice will either have it on its left or on 
its right
so if we're at index i, we can check if the el is either on i+1 or i-1,
if yes the elem is appearing twice otherwise it is not. 
tc = O(n)
*/

/*optimal 
array is sorted, so we can use binary search
in binary search, we split the array in half and then eliminate.
so we find a property of the single el to eliminate accordingly. 
the el in the array are appearing twice so they can be seen as a pair,
elements in the left half have index as (even, odd) and the right half of the number
have index as (odd, even) 
eliminate the part where  your element is not there
to fig out which part to eliminate, use mid index to compute whether we 
are standing on left or right half, if we are on odd index and left element 
is not the same, we eleminate left half. 
*/

#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&arr){
  int n = arr.size();
  //for one sized array
  if(n==1) return arr[0];
  for(int i=0;i<n; i++){
    if(i==0) {
      if(arr[i]!= arr[i+1]) return arr[i];
    }
    else if(i==n-1){
      if(arr[i]!=arr[i-1]) return arr[i];
    } 
    else if(arr[i]!= arr[i+1] && arr[i]!= arr[i-1]) return arr[i];
  }
}

int optimal(vector<int> &arr){
  int n = arr.size();

  //for one sized arr
  if(n==1) return arr[0];

  //condition for first element
  if(arr[0]!= arr[1]) return arr[0];

  //condition for last element
  if(arr[n-1]!= arr[n-2]) return arr[n-1];

  int low = 1;
  int high = n-2;
  while(low <= high){
    int mid = (low+high)/2;
    if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];

    //standing on the left half 
    if((mid%2==1 && arr[mid-1]== arr[mid]) || (mid%2==0 && arr[mid+1]==arr[mid])){
      //eliminate the left half
      low = mid+1;
    } else{
      //eliminate the right half
      high = mid - 1;
    }
  }
  return -1;
}


int main(){
  vector<int> arr = {1,1,2,2,3,3,4,5,5,6,6};
  cout <<"Brute force: "<< brute(arr) <<endl;
  cout <<"Optimal force: "<< optimal(arr);
  return 0;
}
