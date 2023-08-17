/*Next Permutation
Permutation is no of ways of rearrangement 
*/

/*
Edge case
if the given no is the last possible permutaion, then the ans would be the
first possible permutaion.
*/

/*Brute force
generate all permutations in the sorted way using recursion
and then find the given number in the ques using linear search and
return the next element.
tc will be of very high order so avoid this approach.
*/

/*
better approach is to use in-built stl named as 
next_permutation(A.begin(), A.end())
this takes two arguments which are beginning and end of the array.
*/ 

/*
Optimal solution
1. find the break point(i) from the end where the A[i] < A[i+1].
(if we start from the front and the array is in the ascending order or 
descending order, there will be no dip, but if we start from the end, we can find a dip
starting nearly from n-2)
to find the break point, we will traverse the array from the back and find value of 
the break point idnex. 
2. if no break point exists, ie , the array is sorted in decreasign order, the 
given permutaio is the last, so will reverse the array and give the first permutaion possible. 
3. if break point exists,
3.1 we will find the smallest number which is lesser than index eleemnt and swap it with index element.
3.2 reverse the rest of the right half array.

tc = O(3n)
sc= O(1)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector <int> &A){
  int ind = -1;
  int n= A.size();

  //find the break point index
  for(int i=n-2; i>=0; i--){
    if(A[i]<A[i+1]){
      ind = i;
      break;
    }
  }

  //edge case - no dip
  if(ind == -1){
    reverse(A.begin(), A.end());
    return A;
  }

  //swapping of array element after finding the dip index
  for(int i=n-1; i>ind; i--){
    if(A[i]>A[ind]){
      swap(A[i],A[ind]);
      break;
    }
  }
  //array is in asc/desc order, reversing will do the needful
  reverse(A.begin()+ind+1, A.end());
  return A;
}

int main(){
vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}