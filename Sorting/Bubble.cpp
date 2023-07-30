#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n){
  for(int i=n-1; i>=1; i--){
    //this loop is for the no of iterations
    int didSwap = 0; //optimization technique, if no swap happens in the first iteration, that means array is already sorted.
    for(int j=0; j<=i-1; j++){
      //this loop iterates the entire array and pushes the largest element to the last
      if(arr[j]>arr[j+1]){
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        didSwap = 1;
      }
    }
    if(didSwap == 0) break;
    cout << "runs" << endl;
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

  bubbleSort(arr, n);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  
  return 0;
}