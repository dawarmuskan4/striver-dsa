#include<bits/stdc++.h>
using namespace std;

void recBubbleSort(int arr[], int n){
  if(n==1) return;
  int didSwap = 0; // to check if swapping happens

  for(int j=0; j<=n; j++){
    if(arr[j]>arr[j+1]){
      int temp = arr[j+1];
      arr[j +1] = arr[j];
      arr[j] = temp;
      didSwap = 1;
    }
  }
  if(didSwap==0) return; //if no swapping happens
  recBubbleSort(arr,n-1);
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

  recBubbleSort(arr, n);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
  return 0;
}