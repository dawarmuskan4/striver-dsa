/*First and last occurence of x*/

/*Brute force is to use linear search
take two variable first and last initialise both to -1.
when you find the first occ chnge first to that index and traverse the remaining array
and update the last variable. 
tc= O(n)*/

/*Better appraoch using binary search
tc = O(nlogn)
we can use lower bound and upper bound solution for this problem.

*/
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
    pair<int , int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
}

int main(){
  vector<int> arr={0,1,1,5};
  int n=arr.size();
  int x=1;
  return 0;
}