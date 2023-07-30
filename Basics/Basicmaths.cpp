#include <bits/stdc++.h>
using namespace std;

int extractNumber(int n)
{
  while (n > 0)
  {
    int unit = n % 10;
    n = n / 10;
    cout << unit << " ";
  }
  cout << endl;
  return 0;
}

int countDigits(int n)
{
  int count = 0;
  while (n > 0)
  {
    int unit = n % 10;
    count++;
    n = n / 10;
  }
  cout << count << endl;
  return 0;
}

int reverseNumber(int n)
{
  int revNum = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    n = n / 10;
    revNum = (revNum * 10) + lastDigit;
  }
  cout << revNum << endl;
  return 0;
}

bool isPalindrome(int x)
{
  int ans = 0;
  int temp = x;
  while (temp > 0)
  {
    int lastDigit = temp % 10;
    ans = (ans * 10) + lastDigit;
    temp = temp / 10;
  }

  if (ans == x)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool checkArmstrong(int n)
{
  int sum = 0;
  int temp = n;

  while (temp > 0)
  {
    int ld = temp % 10;
    sum = sum + (ld * ld * ld);
    temp = temp / 10;
  }
  if (sum == n)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void printDivisors(int n)
{
  int sum = 0;
  for (int i = 1; i < n; i++)
  {
    if (n % i == 0)
    {
      cout << i << " ";
      sum += i;
    }
  }
  cout << endl
       << "Sum is " << sum << endl;
}

int sumAllDivisors(int n)
{
  int sum = 0;
  for (int i = 1; i <= n; i++)
  {
    sum += (n / i) * i;
  }
  return sum;
}

bool isPrime(int n)
{
  int count = 0;
  for (int i = 1; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      count++;
      if ((n / i) != i)
        count++;
    }
  }
  if (count == 2)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  cout << "Enter a number ";
  int num;
  cin >> num;
  // extractNumber(num);
  // countDigits(num);
  // reverseNumber(num);
  // printDivisors(num);
  cout << sumAllDivisors(num);
  return 0;
}