#include<bits/stdc++.h>
using namespace std;

/* 2 sum problem
Case1: Check whether two elements in the array exists which gives us the desired sum
Case2: Check which two elements in the array gives us the desired sum.
*/

/* Brute force TC=> O(n^2)
pick up an element and check with every element
for(int i=0; i<n; i++){
  for(int j=0; j<n; i++){
    if(i==j) continue;
    if(arr[i]+ arr[j] = target){
      return "Yes" //case 1
    } return "No"
  }
}

optimised => slightly lesser than O(n^2) but close to O(n^2)
for(int i=0; i<n; i++){
  for(int j=i+1; j<n; i++){
    if(arr[i]+ arr[j] = target){
      return "Yes" 
    } return "No"
  }
}
*/

/* Better => Hashing =>TC = O(n*logn) sc=> O(n)
in case of unordered map => O(n)
best for case 2, optimal solution not preffered 
case1
vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> mpp;
  int n=nums.size();
  for(int i=0; i<n; i++){
      int num = nums[i];
      int more = target - num;
      if(mpp.find(more) != mpp.end()){
          return {mpp[more], i};
      }
      mpp[num] = i;
  }
  return{-1,-1};
}
*/
/* Good for case 1
Optimal solution 
we will first sort the array and will try to choose the numbers in a greedy way.
We will keep a left pointer at the first index and a right pointer at the last index. 
Now until left < right, we will check the sum of arr[left] and arr[right]. 
Now if the sum < target, we need bigger numbers and so we will increment the left pointer.
But if sum > target, we need to consider lesser numbers and so we will decrement the right 
pointer. 
If sum == target we will return either “YES” or the indices as per the question.
But if the left crosses the right pointer, we will return “NO” or {-1, -1}.

using 2 pointer =>TC = O(n) sc=> O(1)
string twoSum(int n, vector<int>&arr, int target){
  int left = 0, right = n-1;
  sort(arr.begin(), arr.end())
  while(left<right){
    int sum = arr[left]+arr[right];
    if(sum == target){
      return "YES";
    }
    else if(sum< target) left++;
    else right--;
  }
  return "NO";
}
*/


vector<int> twoSum(vector<int>& nums, int target) {
  map<int, int> mpp;
  int n=nums.size();
  for(int i=0; i<n; i++){
      int num = nums[i];
      int more = target - num;
      if(mpp.find(more) != mpp.end()){
          return {mpp[more], i};
      }
      mpp[num] = i;
  }
  return{-1,-1};
}

int main(){
  int n = 5;
  vector<int> arr = {2, 6, 5, 8, 11};
  int target = 14;
  vector<int> ans = twoSum( arr, target);
  cout << "This is the answer for variant 2: [" << ans[0] << ", "
    << ans[1] << "]" << endl;
  return 0;
}