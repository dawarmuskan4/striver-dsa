/*Minimums days to make M bouquets
an array will be given which consists of the blooming day for the flowers
the first element in the array is the number of days it takes for the 1st 
kind of flower to bloom. similarly, the second element.
now task is to tell what are the min no of days required uch that you have
ample amount of blooming flowers to mke M bouquets and you should have taken 
K adjacent flowers to have one bouquet.
*/

#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
  int n = arr.size(); //size of the array
  int cnt = 0;
  int noOfB = 0;
  // count the number of bouquets:
  for (int i = 0; i < n; i++) {
      if (arr[i] <= day) {
          cnt++;
      }
      else {
          noOfB += (cnt / k);
          cnt = 0;
      }
  }
  noOfB += (cnt / k);
  return noOfB >= m;
}

int roseGarden(vector<int> arr, int k, int m) {
  long long val = m * 1ll * k * 1ll;
  int n = arr.size(); //size of the array
  if (val > n) return -1; //impossible case.
  //find maximum and minimum:
  int mini = INT_MAX, maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
    maxi = max(maxi, arr[i]);
  }
  //brute force
  // for (int i = mini; i <= maxi; i++) 
  //   if (possible(arr, i, m, k))
  //     return i;
  
  //apply binary search:
  int low = mini, high = maxi;
  while (low <= high) {
      int mid = (low + high) / 2;
      if (possible(arr, mid, m, k)) {
          high = mid - 1;
      }
      else low = mid + 1;
  }
  return low;

  return -1;
}

int main(){
  vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
  int k = 3;
  int m = 2;
  int ans = roseGarden(arr, k, m);
  if (ans == -1)
      cout << "We cannot make m bouquets.\n";
  else
      cout << "We can make bouquets on day " << ans << "\n";
  return 0;
}