/*Koko eating bananas
Koka is an individual 
Return the min integer k such that koko can eat all the bananas within h hours.
k is no of bananas/hour
*/

#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
  int maxi = INT_MIN;
  int n = v.size();
  //find the maximum:
  for (int i = 0; i < n; i++) {
      maxi = max(maxi, v[i]);
  }
  return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
  int totalH = 0;
  int n = v.size();
  //find total hours:
  for (int i = 0; i < n; i++) {
      totalH += ceil((double)(v[i]) / (double)(hourly));
  }
  return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
  //Find the maximum number:
  int maxi = findMax(v);
  //Find the minimum value of k:
  for (int i = 1; i <= maxi; i++) {
      int reqTime = calculateTotalHours(v, i);
      if (reqTime <= h) {
          return i;
      }
  }
  return maxi;
}

int minRate(vector<int> v, int h){
  int low = 1;
  int high = findMax(v);
  int ans = INT_MAX;
  while(low <= high){
    int mid = (low+high)/2;
    int reqTime = calculateTotalHours(v, mid);
    if(reqTime <= h){
      ans = mid;
      high = mid - 1;
    } else{
      low = mid+1;
    }
  }
  return ans;
}

int main()
{
  vector<int> v = {7, 15, 6, 3};
  int h = 8;
  int ans = minimumRateToEatBananas(v, h);
  cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
  int ans2 = minRate(v, h);
  cout << "Koko should eat atleast " << ans2 << " bananas/hr.\n";
  return 0;
}