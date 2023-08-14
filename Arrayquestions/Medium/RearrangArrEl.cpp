/*Rearrange array elements which has equal no of positives and negatives
and return an array of alternately positive and negative values.*/

/*Brute force
Take two empty arrays of size n/2 each, pos and neg.
Put the positive elem in the pos array and negative elem in the neg array. 
After segregating each pos and neg element, we start putting them alternatively
back into the orginal array.
TC= O(n+n/2)
SC = O(n) (we took two arrays of size n/2 each)
*/

/*Optimal 
Take a empty ans array of size n. The pos elem will be placed at the even index
and the neg elem at the odd index. take two pointers pos n neg at index 0 and 1.
now traverse the original array and when u encounter pos element, put it at the first
available pos index in the ans array and same for the neg elemet, put it at the first 
available neg index in the ans array.
TC= O(n)
SC = O(n)
*/

#include<bits/stdc++.h>
using namespace std;
//variety 1 => eq no of positives and negatives
vector<int> rearrangeArray(vector<int> &nums){
  int n= nums.size();
  vector <int> ans(n,0);
  int posIndex = 0 , negIndex = 1;
  for(int i=0; i<n; i++){
    if(nums[i]<0){
      ans[negIndex]=nums[i];
      negIndex += 2;
    } else{
      ans[posIndex] = nums[i];
      posIndex += 2;
    }
  }
  return ans;
}

/*
variety 2 => unequal no of positives and negatives => two case pos>neg & pos<neg
arrange the positives and negatives and whatever left don't change their order.
use brute force solution
create two arrays and push pos in one and negel in other.
then take elements from the pos n neg array and arrange equal no of pos and neg 
el alternatively in the org array.
for the remaining elements check which array size is greater and then add those 
el to the org array.
TC = O(n) + O(min(pos, neg)) + O(leftovers)
O(min(pos, neg)) + O(leftovers) => this has worst complexity of O(n)
so resultant TC = O(2n)
SC = O(n)
*/
vector<int> alternateNumbers(vector<int> &a){
  vector<int> pos, neg;
  int n=a.size();
  //this ensures pos and neg are arranged in alernate positions
  for(int i=0; i<n; i++){
    if(a[i]>0){
      pos.push_back(a[i]);
    }else{
      neg.push_back(a[i]);
    }
  }

  if(pos.size() > neg.size()){
    for(int i=0; i<neg.size(); i++){
      a[2*i] = pos[i];
      a[2*i+1] = neg[i];
    }
    int index = neg.size()*2;
    for(int i=neg.size() ; i<pos.size(); i++){
      a[index]= pos[i];
      index++;
    }
  } else{
    for(int i=0; i<pos.size(); i++){
      a[2*i] = pos[i];
      a[2*i+1] = neg[i];
    }
    int index = pos.size()*2;
    for(int i=pos.size() ; i<neg.size(); i++){
      a[index]= neg[i];
      index++;
    }
  } 
  return a;
}

int main(){
  vector<int> arr1 = {1,2,-4,-5};
  vector<int> ans1 = rearrangeArray(arr1);
  cout << "Rearranged array is " ;
  for(int i=0; i<ans1.size(); i++){
    cout << ans1[i] << " ";
  }
  cout << endl;

  vector<int> arr2 = {1,2,-4,-5,3,4,-1, 8,9};
  vector<int> ans2 = alternateNumbers(arr2);
  cout << "Rearranged array is " ;
  for(int i=0; i<ans2.size(); i++){
    cout << ans2[i] << " ";
  }
  return 0;
}