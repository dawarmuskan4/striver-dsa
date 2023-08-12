#include<bits/stdc++.h>
using namespace std;
/* union of two sorted arrays
brute force is by creating a set and iterating both arrays 
and inserting elements in the set. The set will only contains 
unique elements. */

/*Optimal Approach
Two pointer approach. We will keep the first pointer on the first element of 
the first array and second ointer on the first element of the second array. 
We will initialise a union list which is empty. 
You will start iterating the arrays and comparing the elements inthe array
like comparing both arrays first elements and we will insert the smaller of the two into 
our list/vector. The pointer in the array from which the elemnt has been inserted 
will move to the next element and this will continue until the iteration of a 
array is completd. If one array iteration is completed. then next array will be iterated
and elements will be pushed to the list. 
*/


int main(){
  int n1;
  cout << "enter arr1 size "; 
  cin >> n1;

  cout << "Enter array1 element ";
  int arr1[n1];
  for(int i=0; i<n1; i++){
    cin >> arr1[i];
  }

  int n2;
  cout << "enter arr2 size "; 
  cin >> n2;

  cout << "Enter array2 element ";
  int arr2[n2];
  for(int i=0; i<n2; i++){
    cin >> arr2[i];
  }
  /*Brute force 
  set <int> st;

  for(int i=0; i<n1; i++){
    st.insert(arr1[i]);
  }

  for(int i=0; i<n2; i++){
    st.insert(arr2[i]);
  }

  int n3= st.size();
  int unionArr[n3];
  int i=0;
  for(auto it: st){
    unionArr[i++] = it;
    cout << it << " ";
  }
*/

  /*Optimal approach*/

  int i=0;
  int j=0;
  vector<int> unionArr;
  while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
      if(unionArr.size()==0 || unionArr.back() != arr1[i]){
        unionArr.push_back(arr1[i]);
      }
      i++;
    } else{
      if(unionArr.size()==0 || unionArr.back() != arr2[j]){
        unionArr.push_back(arr2[j]);
      }
      j++;
    }
  }

  while(j<n2){
    if(unionArr.size()==0 || unionArr.back() != arr2[j]){
      unionArr.push_back(arr2[j]);
    }
    j++;
  }

  while(i<n1){
    if(unionArr.size()==0 || unionArr.back() != arr1[i]){
      unionArr.push_back(arr1[i]);
    }
    i++;
  }
  return 0;
}