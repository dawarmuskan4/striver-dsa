#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
  for(int i=0; i<=n-1; i++){
    //this loop is for the no of iterations
    for(int j=i; j>0; j--){
      //this loop iterates the entire array and swaps adjacent elements.
      if(arr[j-1]>arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main(){
  int n;
  cout << "enter arr size "; 
  cin >> n;

  cout << "Enter array element ";
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  insertionSort(arr, n);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  
  return 0;
}