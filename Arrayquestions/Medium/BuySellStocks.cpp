/*Buy and Sell stocks to maximise profit*/

/*
TC = O(n)
SC = O(1)
we used dynamic programming in this problem. 
*/
#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
  int mini = prices[0];
  int maxProfit = 0;
  int n= prices.size();

  for(int i=1; i<n; i++){
    int cost = prices[i]-mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }
  return maxProfit;
}

int main(){
  vector<int> arr = {7,1,4,5,9,3};
  int ans = maximumProfit(arr);
  cout << "Maximum profit is " << ans; 
  return 0;
}