/*Find leaders in an array
and leader means everything in the right should be smaller
last element will always be a leader*/ 

/*Bruter force
take up an element and check on thr right if there is any element lesser than the
current one.
for(int i=0; i<n; i++){
  leader = true;
  for(int j=i+1; j<n; j++){
    if(a[j]< a[i]){
      leader = false;
      break;
    }
  }
}
if(leader == true) ans.add(a[i]);

tc ~= O(n^2)
sc = O(n) at worst case
*/

/*
Optimal Solution
we will traverse the array from the end and find the max elemtn.
If we find a new max element on the left, we can say all elements to its right are
smaller, that's how we find a leader.

tc = O(n)
sc = O(N) in worst case when all the elemnts are leaders.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
  int max = arr[n - 1];
  ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--){
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }
  }
  //if have to return the sorted ans
  sort(ans.begin(), ans.end()); //O(nlogn)
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  for(int i = ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}