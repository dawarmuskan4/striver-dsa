/* Set matrix zero
The problem states that you will be given n*m matrix and n and m can be 
different or equal. Matrix only has 0s and 1s.
You've to find the zero and make its entire row and col as 0. 
and you can only use the original zero to make the row n col as 0. 
*/

/*Brute force
iterate on the matrix and find the zero and then mark other elements of 
the row and col as -1. 
iterate one more time and wherever we marked -1 change it to 0. 
#code
markRow(i){
  for(j=0; j<m; j++){
    if(arr[i][j]!= 0){
      arr[i][j] = -1;
    }
  }
}
markCol(j){
  for(i=0; i<n; i++){
    if(arr[i][j]!= 0){
      arr[i][j] = -1;
    }
  }
}
markZero(){
  for(i=0; i<n; i++){
    for(j==0; j<m; j++){
      if(arr[i][j]==0){
        markRow(i);
        markCol(j);
      }
    }
  }
  for(int i=0; i<n; i++){
    for(j=0; j<m; j++){
      if(arr[i][j]==-1){
        arr[i][j] = 0;
      }
    }
  }
}

TC = O(n*m)*(n+m)+(n*m) ~ O(n^3)
*/

/*Better solution
we'll still have to traverse the matrix and find where we've 0 in the matrix.
and rather of changing it to -1, we'll mark the row and col which has to be
eventually changed to 0 in the end. 
to keep the mark, we have to introduce col matrix of size m and row matrix
of size n.
Initially will mark everyone as 0 and when we reach a 0 in the original array,
we will mark 1 in our introduced row and col array. 
Now will reiterate and check for every element if it the same row n col has been marked
in our array. if yes, we'll change 1 to 0 in the original array. 

tc = O(2*n*m) ~ O(n^2)
sc= O(n)+ O(m)
*/

/*
to optimise the better solution, we need to optimise the space complexity which
means we'll have to mark it in the matrix itself, rather than taking new matrices. 
We can mark in 1st row and 1st col, but this gives a problem that cell matrix[0][0]
is taken twice. to overcome this problem we take an extra varible col[0]=1.
now first row of the matrix will serve the purpose of row array and 1st col with 
col[0] var will serve the purpose of col array.
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
  int col[m]= {0}; 
  int row[n] = {0};
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(matrix[i][j]==0){
        //mark ith index of row with 1
        row[i]= 1;
        //mark jth index of col with 1
        col[j]=1;
      }
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      //mark all (i, j) as 0 if row[i] or col[j] = 1
      if(row[i] || col[j]){
        matrix[i][j] = 0;
      }
    }
  }
  return matrix;
}

int main(){
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int>> ans = zeroMatrix(matrix, n, m);
  cout << "The Final matrix is: \n";
  for (auto it : ans) {
      for (auto ele : it) {
          cout << ele << " ";
      }
      cout << "\n";
  }
  return 0;
}