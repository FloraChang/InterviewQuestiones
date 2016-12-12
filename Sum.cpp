/* 
Implement a function that adds two integers represented by “series” of characters.
e.g. [‘1’, ‘0’, ‘0’] + [‘1’,’2’,’3’] => [‘2’,’2’,’3’]

input and output are the same type
negative integers? No. Inputs are zero or positive integers.

Test case:
100 + 123
0 + 0
0 + 100
99 + 999
1 + 2999
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> Sum( vector<int> num1, vector<int> num2 )
{
  stack<int> result;
  
  if( num1.size() == 0 ) {
    return num2;
  }
  if( num2.size() == 0 ) {
    return num1;
  }
  
  int index1 = num1.size()-1;
  int index2 = num2.size()-1;
  
  int c = 0; // carry
  int sum = 0;
  
  while( index1 >= 0 && index2 >= 0 ){
    
    sum = num1[index1]+num2[index2]+c;
    result.push( sum % 10 );
    c = sum / 10;
    
    index1--;
    index2--;
  }
  
  while( index1 >=0 ) {
    sum = num1[index1] + c;
    result.push( sum % 10 );
    c = sum/10;
    index1--;
  }
  
  while( index2 >= 0 ){
    sum = num2[index2] + c;
    result.push( sum % 10 );
    c = sum/10;
    index2--;
  }
  
  if( c > 0 ) {
    result.push( c );
  }
  
  // return the vector of sum
  vector<int> sum_vec;
  
  while( !result.empty() ) {
    sum_vec.push_back( result.top() );
    result.pop();
  }
  
  return sum_vec;
}

/*
int main()
{
  int a[3] = {9,9,9};
  int b[2] = {9,9};
  vector<int> num1 ( a, a + (sizeof(a)/sizeof(int)));
  vector<int> num2 ( b, b + (sizeof(b)/sizeof(int)));
  vector<int> sum = Sum( num1, num2 );
  
  for( int i = 0; i < sum.size(); i ++ )
  {
    cout << sum[i];
  }
  cout << endl;
  
  return 1;
}
*/

/*
time complexity: O(N)
stack.push/pop takes O(1)
it would be better to return a pointer/reference of the sum instead of its copy.
*/

