#include<bits/stdc++.h>
using namespace std;

//brute approach
int secondLargest(int a[], int n){
  int largest = a[0];
    for(int i=0; i<n;i++){
        if(a[i]>largest){
            largest = a[i];
        }
    }
    int slargest = -1;
    for(int i=0; i<n; i++){
        if(a[i]>slargest && a[i]!= largest){
            slargest = a[i];
        }
    }
    return slargest;
}

//optimal approach
int secLargest(int a[], int n){
  int largest = a[0];
    int slargest = -1; 

    for(int i=1; i<n; i++){
        if(a[i]> largest){
            slargest = largest;
            largest = a[i];
        }else if(a[i]<largest && a[i]>slargest){
            slargest = a[i];
        }
    }
    return slargest;
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

  cout << secLargest(arr, n);
  return 0;
}