/*
Consider N coins aligned in a row. Each coin is showing either heads or 
tails. The adjacency of these coins is the number of adjacent pairs of coins
with the same side of face.
  
You are giving an implementation of a function:
    int solution(vector<int> &A);
that, given a non-empty zero-idexed array A consisting of N integers 
representing the coins, returns the maximum possible adjacency that can be 
obtained by reversing exactly one coin (that is, one of the coins must be 
reversed). Consecutive elements of array A represent consecutive coins in 
the row. Array A contains only 0s and/or 1s: 
        0 represents a coin with heads facing up; 
        1 represents a coin with tails facing up. 
    
For example, given array A consisting of six numbers, such that:
    
        A[0] = 1 
        A[1] = 1 
        A[2] = 0
        A[3] = 1 
        A[4] = 0 
        A[5] = 0
    
the function should return 4. The initial adjacency is 2, as there are 
two pairs of adjacent coins with the same side facing up, namely (0, 1) and 
(4, 5). After reversing the coin represented by A[2], the adjacency equals 4
, as there are four pairs of adjacent coins with the same side facing up, 
namely: (0, 1), (1, 2), (2, 3) and (4, 5), and it is not possible to obtain 
a higher adjacency. 
    
Unfortunately, despite the fact that the funciton may return expected 
result for hte example input, there is a bug in the implementation, which 
may produce incorrect results for other inputs. Find the bug and correct it.
You should modify at most three lines of code.

N is an integer within the range of [1....1'000]. And it has to be done 
as O(N) time and O(1) space. Elements of input arrays can be modified.

int solution(int *A, int A_length) {
    int n = A_length;
    int result = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        if (A[i] == A[i + 1])
            result = result + 1;
    }
    int r = 0;
    for (i = 0; i < n; i++) {
        int count = 0;
        if (i > 0) {
            if (A[i - 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (i < n - 1) {
            if (A[i + 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (count > r)
            r = count;
    }
    return result + r;
}
*/


#include <iostream>
#include <vector>

using namespace std;

void printVector( vector<int> &A )
{
    vector<int>::iterator it;
    for( it = A.begin(); it != A.end(); it++ )
    {
        cout << *it <<" ";
    }
    cout << endl;
}

int solution(vector<int> & A) {
    
    int n = (int)A.size();
    int result = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        // Count the adjacent coins wtih the same face
        // ex. ( 1, 1 ), ( 0, 0 )
        if (A[i] == A[i + 1])
            result = result + 1;
    }
    
    // Key: You should set r to "-1", not "0",
    // otherwise, you'll fail in some cases, such as [1, 1] because r = max(r, count) would make r = 0, which is wrong.
    int r = -1;
    
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        
        // Assume you will flip "i" coin, check adjancent A[i-1], A[i], A[i+1]
        // ( 0, 0, 0 ) -> count = -2
        // ( 0, 0, 1 ) -> count = 0
        // ( 0, 1, 0 ) -> count = 2
        // ( 1, 0, 0 ) -> count = 0
        // ( 0, 1, 1 ) -> count = 0
        // ( 1, 1, 0 ) -> count = 0
        // ( 1, 0, 1 ) -> count = 2
        // ( 1, 1, 1 ) -> count = -2
        if (i > 0)
        {
            if (A[i - 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }
        if (i < n - 1)
        {
            if (A[i + 1] != A[i])
                count = count + 1;
            else
                count = count - 1;
        }

        r = max(r, count);
    }
    return result + r;
}

int main()
{
    vector<int> A ( { 1, 1, 0, 1, 0, 0 } );
    vector<int> B ( { 1 } );
    vector<int> C ( { 1, 1 } );
    
    cout<< solution(A) << endl; // 4
    cout<< solution(B) << endl; // 0
    cout<< solution(C) << endl; // 1
}
