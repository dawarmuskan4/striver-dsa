/*Rotate Matrix or Rotate Image by 90deg
You are given a n*n matrix and you have to rotate the matrix by 90deg in 
the clockwise direction
*/

/*Brute force
Take another dummy matrix of n*n, and then take the first row of the 
matrix and put it in the last column of the dummy matrix, take the second 
row of the matrix, and put it in the second last column of the matrix and 
so.
tc = O(N^2)
sc = O(N^2)
*/

/*Optimial solution
first transpose the matrix and then reverse the rows
tc=O(n/2*n/2) + O(n*n/2)
*/

#include<bits/stdc++.h>
using namespace std;

vector < vector < int >> rotateMat(vector<vector<int>> &mat){
  int n= mat.size();
  for(int i=0; i<n-1; i++){
    for(int j=i+1;j<n; j++){
      swap(mat[i][j], mat[j][i]);
    }
  }
  for(int i=0; i<n; i++){
    //row is max[i]
    reverse(mat[i].begin(), mat[i].end());
  }
}

vector<vector <int>> rotateMatrix(vector<vector<int>> &matrix){
  int n=matrix.size();
  vector<vector <int>> ans(n, vector<int> (n,0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      ans[j][n-i-1] = matrix[i][j];
    }
  }
  return ans;
}

int main(){
  vector < vector < int >> arr;
  arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector < vector < int >> rotated = rotateMatrix(arr);
  cout << "Rotated Image " << endl;
  for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
      cout << rotated[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";

  vector < vector < int >> rotated1 = rotateMat(arr);
  cout << "Rotated Image " << endl;
  for (int i = 0; i < rotated1.size(); i++) {
    for (int j = 0; j < rotated1[0].size(); j++) {
      cout << rotated1[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}