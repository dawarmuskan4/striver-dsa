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
tc = O(3n)
sc= O(1)
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector <int> &A){
  int ind = -1;
  int n= A.size();
  for(int i=n-2; i>=0; i--){
    if(A[i]<A[i+1]){
      ind = i;
      break;
    }
  }
  if(ind == -1){
    reverse(A.begin(), A.end());
    return A;
  }
  for(int i=n-1; i>ind; i--){
    if(A[i]>A[ind]){
      swap(A[i],A[ind]);
      break;
    }
  }
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