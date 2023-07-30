#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
  for(int i=0; i<=n-1; i++){
    //outer loop handles no of iterations
    int didSwap = 0;
    for(int j=i; j>0; j--){
      // inner loop iterates the entire array and swaps the adjacent numbers accordingly. 
      if(arr[j-1]>arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j]= temp;
      }
      didSwap = 1;
    }
    if(didSwap == 0){
      break;
    }
    cout << "run" << endl;
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