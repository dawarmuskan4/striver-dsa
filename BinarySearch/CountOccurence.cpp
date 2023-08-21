
#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr, int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key){
    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]){
            s = mid + 1;
        }
        else if(key < arr[mid]){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOcc(arr,n,k);
    if(first==-1) return {-1,-1};
    int last = lastOcc(arr,n,k);
    return {first, last};
}

int count(vector<int> &arr, int n, int k){
    pair<int, int> ans = firstAndLastPosition(arr,n,k);
    if(ans.first==-1) return 0;
    return ans.second-ans.first+1;
}

int main(){
    vector<int> arr={0,1,1,5};
    int n=arr.size();
    int x=1;
    return 0;
}