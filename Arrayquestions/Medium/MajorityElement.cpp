/*Majority elements problem
the element should appear more than n/2 time */

/* Brute force  => TC= O(n^2)
Pick up an element and count its no of appearance and
then check if its count > n/2, if yes return true
*/

/*Better solution using hashing
Store occurence of elements in a hashmap and then compare the occurence
with size of array/2. if occuernce is greater then return the element (key
in the hashmap)
*/

/*
Moore Voting Algorithm
TC = O(n)+O(n)
SC = O(1)
Approach
1. Initialize 2 variables:
  Count –  for tracking the count of element
  Element – for which element we are counting
2. Traverse through the given array.
  If Count is 0 then store the current element of the array as Element.
  If the current element and Element are the same increase the Count by 1.
  If they are different decrease the Count by 1.
3.The integer present in Element should be the result we are expecting 

*/
#include<bits/stdc++.h>
using namespace std;

int mooreVotingAlgorithm(vector <int> v){
  int cnt = 0;
	int el;

  //applying the algorithm
	for(int i=0; i<v.size(); i++){
		if(cnt == 0){
			cnt = 1;
			el=v[i];
		}
		else if(v[i] == el){
			cnt++;
		}
		else{
			cnt--;
		}
	}
  //chck if stored element is the majority element or not
	int count = 0;
	for(int i=0; i<v.size(); i++){
		if(v[i]== el) count++;
	}
	if(count> (v.size()/2)){
		return el;
	}
	return -1;
}

int majorityElement(vector <int> v){
  int n=v.size();
  map<int, int> mpp;
  for(int i=0; i<n; i++){
    mpp[v[i]]++;
  }
  for(auto it:mpp){
    if(it.second > n/2){
      return it.first;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
  int ans = majorityElement(arr);
  cout << "The majority element is: " << ans << endl;
  return 0;
}