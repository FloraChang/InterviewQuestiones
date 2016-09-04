/*
 Find the index K, 0 < = K <= N, such that the array A is split to two parts [0, K-1] and [K, N],
 where the first array contains the numbers equals to integer X and second array contains the same
 number of non X integers.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int X, vector<int> &A) {
    
    int size = (int)A.size();
    int similar[size];
    int different[size];
    
    int count = 0;
    
    // count number similar to X from left to right
    for( int i = 0; i < size; i++ )
    {
        if( A[i] == X )
        {
            count++;
        }
        similar[i] = count;
    }

    count = 0;
    
    // count number different from X from right to left
    for( int i = size - 1; i >= 0; i-- )
    {
        if( A[i] != X )
        {
            count++;
        }
        different[i] = count;
    }
    
    int K = -1;
    
    // find the partition K
    for( int i = 1 ; i < size ; i++ )
    {
        if( similar[i-1] == different[i] )
        {
            K = i;
            break;
        }
    }
    
    // special case: cannot find K in range [1, size - 1]
    if( K == -1 )
    {
        if( similar[size-1] == 0 )
        {
            K = size;
        }
        else
        {
            K = 0;
        }
    }
    
    return K;
}


int main()
{
    vector<int> A = { 5, 5, 1, 7, 2, 3, 5 }; // 4
    
    vector<int> B = { 1 }; // 1
    
    vector<int> C = { 0, 0, 0, 1, 1 }; // 2

    cout << solution( 2, B ) << endl;
    
    return 1;
}
