#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
  /*
   * * * *
   * * * *
   * * * *
   * * * *
   */
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << "* ";
    }
    cout << endl;
  }

}

void pattern2(int n){
  /*
   *
   * *
   * * *
   * * * *
   * * * * *
  */
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < i; j++){
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern3(int n){
  /*
    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
  */
  for (int i = 1; i <= n; i++){
    int count = 1;
    for (int j = 0; j < i; j++){
      cout << count << " ";
      count++;
    }
    cout << endl;
  }

}

void pattern4(int n){
  /*
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
  */
  int count = 1;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < i; j++){
      cout << count << " ";
    }
    count++;
    cout << endl;
  }
}

void pattern5(int n){
  /*
    * * * * *
    * * * *
    * * *
    * *
    *
  */
  for (int i = n; i >= 1; i--){
    for (int j = 0; j < i; j++){
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern6(int n){
  /*
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
  */
  for (int i = n; i >= 1; i--){
    int count = 1;
    for (int j = 0; j < i; j++){
      cout << count << " ";
      count++;
    }
    cout << endl;
  }
}

void pattern7(int n){
  /*
        *
       ***
      *****
     *******
    *********
  */
  for (int i = 0; i<n; i++){
    //space
    for (int j = 0; j<n-i-1 ; j++){
      cout << " ";
    }
    //star
    for(int j=0; j<2*i+1; j++){
      cout << "*";
    }
    //space
    for(int j=0; j<n-i-1; j++){
      cout << " ";
    }
    cout << endl;
  }
}

void pattern8 (int n){
  /*
    *********
     *******
      *****
       ***
        *
  */
  for (int i = n-1; i >= 0; i--){
    //space
    for (int j = 0; j<n-i-1 ; j++){
      cout << " ";
    }
    //star
    for(int j=0; j<2*i+1; j++){
      cout << "*";
    }
    //space
    for(int j=0; j<n-i-1; j++){
      cout << " ";
    }
    cout << endl;
  }
}

void pattern9(int n){
  /*
        *
       ***
      *****
     *******
    *********
    *********
     *******
      *****
       ***
        *
   */
  // upward pyramid
  for (int i = 0; i < n; i++){
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    // star
    for (int j = 0; j < 2 * i + 1; j++){
      cout << "*";
    }
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    cout << endl;
  }
  // inverted pyramid
  for (int i = n - 1; i >= 0; i--){
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    // star
    for (int j = 0; j < 2 * i + 1; j++){
      cout << "*";
    }
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    cout << endl;
  }
}

void pattern10(int n){
  /*
    *
    * *
    * * *
    * * * *
    * * * * *
    * * * *
    * * *
    * *
    *
  */
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < i; j++){
      cout << "* ";
    }
    cout << endl;
  }
  for (int i = n-1; i >= 1; i--){
    for (int j = 0; j < i; j++){
      cout << "* ";
    }
    cout << endl;
  }
}

void pattern11(int n){
  /*
    1
    0 1
    1 0 1
    0 1 0 1
    1 0 1 0 1
  */
  int start = 1;
  for (int i = 1; i <= n; i++){
    if(i%2!=0) start = 1;
    else start = 0;
    for (int j = 0; j < i; j++){
      cout << start << " ";
      start = 1- start;
    }
    cout << endl;
  }
}

void pattern12(int n){
  /*
    1      1
    12    21
    123  321
    12344321
  */ 
  int space = 2*(n-1);
  for (int i = 1; i <= n; i++){
    //numbers
    for (int j = 1; j <= i; j++)
    {
      cout << j<< " ";
    }
    //space
    for (int j = 1; j<=space; j++)
    {
      cout << "  ";
    }
    //numbers
    for (int j = i; j >= 1; j--){
      cout << j << " ";
    }
    cout << endl;
    space -=2;
  }
}

void pattern13(int n){
  /*
    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15
  */
  int count = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<i; j++){
      cout << count << " ";
      count++;
    }
    cout << endl;
  }
}

void pattern14(int n){
  /*
    A
    A B
    A B C
    A B C D
    A B C D E
  */
  for (int i = 1; i <= n; i++){
    char ch = 'A';
    for (int j = 0; j < i; j++){
      cout << ch << " ";
      ch += 1;
    }
    cout << endl;
  }
}

void pattern15(int n){
  /*
    A B C D E
    A B C D
    A B C
    A B
    A
  */
  for (int i = 1; i <= n; i++){
    char ch = 'A';
    for (int j = n; j>=i; j--){
      cout << ch << " ";
      ch += 1;
    }
    cout << endl;
  }
}

void pattern16(int n){
  /*
    A
    BB
    CCC
    DDDD
    EEEEE
  */
  char ch = 'A';
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < i; j++){
      cout << ch;
    }
    ch += 1;
    cout << endl;
  }
}

void pattern17(int n){
  /*
        A
       ABA
      ABCBA
     ABCDCBA
    ABCDEDCBA
  */
  for (int i = 0; i < n; i++){
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    // character
    char ch='A';
    int breakpoint = (2*i+1)/2;
    for (int j = 1; j <= 2 * i+1 ; j++){
      cout << ch;
      if(j<=breakpoint) ch++;
      else ch--;
    }   
    // space
    for (int j = 0; j < n - i - 1; j++){
      cout << " ";
    }
    cout << endl;
  }
}

void pattern18(int n){
  /*
    E
    D E
    C D E
    B C D E
    A B C D E
  */
  for (int i = 1; i <= n; i++){
    char ch = 'A'+n-i;
    for (int j = 0; j <i; j++){
      cout << ch << " ";
      ch++;
    }
    cout << endl;
  }
}

void pattern19(int n){
  /*
  ********
  ***  ***
  **    **
  *      *
  *      *
  **    **
  ***  ***
  ********
  */
  // upper part
  int initSpace = 0;
  for (int i=0;i<n;i++){
    // upper left triangle
    for (int j=1; j<=n-i; j++){
      cout << "*";
    }
    //space
    for(int j=0; j<initSpace;j++){
      cout<< " ";
    }
    //upper right triangle
    for (int j=1; j<=n-i; j++){
      cout << "*";
    }
    initSpace += 2;
    cout << endl;
  }

  //lower part
  initSpace = 2*n-2;
  for(int i=1; i<=n; i++){
    // lower left triangle
    for(int j=1;j<=i; j++){
      cout << "*";
    }
    //space
    for(int j=0; j<initSpace; j++){
      cout << ' ';
    }
    // lower right triangle
    for (int j = 1; j<=i; j++){
      cout << "*";
    }
    initSpace -= 2;
    cout << endl;
  }
}

void pattern20(int n){
  /*
    *      *
    **    **
    ***  ***
    ********
    ***  ***
    **    **
    *      *
   */
  // upper part
  int initSpace = 2 * n - 2;
  for (int i = 1; i < n; i++){
    // upper left triangle
    for (int j = 1; j <= i; j++){
      cout << "*";
    }
    // space
    for (int j = 0; j < initSpace; j++){
      cout << ' ';
    }
    // upper right triangle
    for (int j = 1; j <= i; j++){
      cout << "*";
    }
    initSpace -= 2;
    cout << endl;
  }

  // lower part
  initSpace = 0;
  for (int i = 0; i < n; i++){
    // lower left triangle
    for (int j = 1; j <= n - i; j++){
      cout << "*";
    }
    // space
    for (int j = 0; j < initSpace; j++){
      cout << " ";
    }
    // lower right triangle
    for (int j = 1; j <= n - i; j++){
      cout << "*";
    }
    initSpace += 2;
    cout << endl;
  }
}

void pattern21(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i==0 || j==0|| i==n-1 || j==n-1){
        cout << "*";
      }
      else cout << " ";
    } cout << endl;
  }
}

void pattern22(int n){
  /*
    4 4 4 4 4 4 4
    4 3 3 3 3 3 4
    4 3 2 2 2 3 4
    4 3 2 1 2 3 4
    4 3 2 2 2 3 4
    4 3 3 3 3 3 4
    4 4 4 4 4 4 4
  */
  int num = n;
  for (int i = 0; i < 2*n-1; i++){
    for (int j = 0; j < 2*n-1; j++){
      int top=i;
      int left=j;
      int right=(2*n-2)-j;
      int down =(2*n-2)-i;
      cout << (n-min(min(top,down), min(left, right))) << " ";
    }
    cout << endl;
  }
}

int main(){ 
 
  int n;
  cout << "Enter n ";
  cin >> n;
  pattern22(n);
  return 0;
}