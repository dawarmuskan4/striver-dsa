/*Upper BOUND*/
/*It is the smallest index such that arr[ind]>x
TC= O(log(base2)n)
*/

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int x){
  int low = 0, high = n-1;
  int ans = n;
  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]>x){
      ans = mid;
      high=mid - 1;
    } else{
      low = mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {1,2,3,3,3,4,6,6,6,7,7,7,8,9,9};
  int n= arr.size();
  int x = 5;
  cout << upperBound(arr, n, x);
  return 0;
}