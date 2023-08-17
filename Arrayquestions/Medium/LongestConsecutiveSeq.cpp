/*Longest consecutive sequence
search for consecutive elements that are present in the array and 
then return their length.*/

/*Brute force
Traverse the array and find the consecutive numbers, whenever found increase 
the count by 1 and then return that count. 

ls(arr, num){
  for(int i=0; i<n; i++){
    if(arr[i]= num) return num;
    return false;
  }
}
longest = 1;
for(int i=0; i<n; i++){
  x = arr[i];
  count = 1;

  while(ls(arr, x+1) = true){
    x += 1;
    count += 1;
  }
}

tc= O(N^2)
sc = O(1)
*/

/*Better solution
this will be done in case of sorted array. 
‘lastSmaller’ →(to store the last included element of the current sequence), 
‘cnt’ → (to store the length of the current sequence), 
‘longest’ → (to store the maximum length).
Initialize ‘lastSmaller’ with ‘INT_MIN’, ‘cnt’ with 0, and 
‘longest’ with 1(as the minimum length of the sequence is 1).

we will traverse the whole array in one iteration and find the longest sequence.
*/

/*Optimal cse
tc = O(nlogn) for sorting the array + O(n) of the loop => O(n)
sc = O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int longestConsecutiveElements(vector<int> &a){
  int n= a.size();
  if(n==0) return 0;
  int longest = 1;
  unordered_set<int> st;
  for(int i=0; i<n; i++){
    st.insert(a[i]);
  }
  for(auto it: st){
    if(st.find(it-1) == st.end()){
      int cnt =  1;
      int x = it;
      while(st.find(x+1) != st.end()){
        x += 1;
        cnt +=1 ;
      }
      longest = max(longest, cnt);
    }
  }
  return longest;
}

int longestSuccessiveElements(vector<int> &nums){
  if(nums.size()==0) return 0;
  sort(nums.begin(), nums.end());
  int n= nums.size();
  int lastSmaller = INT_MIN;
  int cnt = 0;
  int longest = 1;
  for(int i=0; i<n; i++){
    if(nums[i]-1 == lastSmaller){
      cnt +=1 ;
      lastSmaller = nums[i];
    }
    else if(lastSmaller != nums[i]){
      cnt = 1;
      lastSmaller = nums[i];
    }
    longest = max(longest, cnt);
  }
  return longest;
}

int main(){
  vector<int> a = {100, 200, 1, 2, 3, 4};
  int ans = longestSuccessiveElements(a);
  cout << "The longest consecutive sequence is " << ans << "\n";
  return 0;;
}