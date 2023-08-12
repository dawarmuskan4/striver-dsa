/*
Kadane's algorithm
used to find the maxium subarray sum
*/

/*
Brute force tc= O(n^3)
Intuition: 
Check the sum of every possible subarray and consider the maximum among them.
to get every possible sub array sum, we will use three nested loop.
Approach: 
Iterate over the array using loops
First loop will point to the first element from 0 to n-1
second loop will iterate through the array and from i to n-1
third loop will find the sum from i to j and store the max sum in a variable.
*/
/*
Better solution
by eliminating the third loop and find the sum in the second loop itself 
will optimise the solution to tc of O(n^2)
*/

/*
Optimal solution - Kadane's algorithm 
tc = O(n)
we will iterate the given array with a single loop and while iterating 
we will add the elements in a sum variable. Now, if at any point the sum 
becomes less than 0, we will set the sum as 0 as we are not going to 
consider any subarray with a negative sum. Among all the sums calculated,
we will consider the maximum one.
*/


#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum>maxi) maxi = sum;
            if(sum < 0) sum = 0;
        }
        return maxi;
    }

int main(){ 
  vector<int> arr = {2, -5, -1, 7, -4, -2, 12};
  int ans = maxSubArray(arr);
  cout << "The max sum is: " << ans << endl;
  return 0;
}