#include<bits/stdc++.h>
using namespace std;

/*Brute force TC- O(n1*n2) SC- O(n2)
Take a new intersection array and start comparing elements of first array
with all elements of second array, If found insert in the array and if not move
to next elemtn. the intersection array will not have duplicates.
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
  int ans[n2];
  int vis[n2]={0};
  for(int i=0; i<n1; i++){
    for(int j=0; j<n2; j++){
      if(arr1[i]==arr2[j] && vis[j]==0){
        ans[i] = arr1[i];
        vis[j] = 1;
        break;
      } 
      if(arr1[j]>arr1[i]) break;
    }
  }
  for(int i=0; i<n2; i++){
    cout << ans[i] <<  " ";
  }
  return 0;
}