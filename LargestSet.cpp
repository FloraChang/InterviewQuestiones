/*
 A zero-indexed array A consisting of N different integers is given. 
 The array contains all integers in the range [0..N−1]. Sets S[K] for 0 ≤ K < N are defined as follows:
 S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }. Sets S[K] are finite for each K.
 
 Write a function:
 
    solution(vector<int> &A)
 
 that, given an array A consisting of N integers, returns the size of the largest set S[K] for this array.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

void resetTable( bool* table, int size )
{
    for( int i = 0; i < size; i++ )
    {
        table[i] = false;
    }
}

int solution(vector<int> &A) {
    
    int max_count = 0;
    int count = 0;
    int size = (int)A.size();
    bool *occur = new bool[ size ];
    
    resetTable( occur, size );
    
    for( int i = 0 ; i < size; i++ )
    {
        int num = A[i];
        
        while( occur[num] == false ) // avoid the loop
        {
            count++;
            occur[num] = true;
            num = A[num];
        }
        
        max_count = max( max_count, count );
        count = 0;
    }
    
    return max_count;
}

int main(){
    
    vector<int> A = { 5, 4, 0, 4, 1, 6, 2 };
    cout << solution(A) << endl;
    
    return 0;
}
