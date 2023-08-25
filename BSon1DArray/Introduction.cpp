/*BINARY SEARCH
It is a searching algorithm with a limited sorted search space.
It works by repeatedly dividing the search interval in half, until it 
finds an element that matches or goes out of bounds.
tc = O(log(base2)n)
*/

#include<bits/stdc++.h>
using namespace std;

//iterative approach
int binarySearch(vector<int> &nums, int target){
  int n= nums.size();
  int low = 0, high = n-1;
  while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]== target) return mid;
    else if(nums[mid] < target) low=mid+1;
    else high = mid-1;
  }
  return -1;
}

//recursive approach
int binarySearchh(vector<int> &nums, int low, int high, int target){
  if(low>high) return -1;
  int mid = (low+high)/2;
  if(nums[mid] == target) return mid;
  else if(target > nums[mid]) binarySearchh(nums, mid+1, high, target);
  else binarySearchh(nums, low, mid-1, target);
}

int main(){
  vector<int> nums = {9,2,54,13,16,61,31};
  int target = 16;
  cout << "Iterative approach "<<binarySearch(nums, target) << endl;
  cout << "Recursive approach "<<binarySearchh(nums,0, nums.size()-1, target) << endl;
  return 0;
}