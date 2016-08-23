#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int solution(vector<int> &A) {

    int size = (int)A.size();
    int *max_left = new int[size];
    int *min_right = new int[size];

    int maximum = INT_MIN;
    for( int i = 0; i < size; i++ )
    {
        maximum = max( maximum, A[i] );
        max_left[i] = maximum;
        // cout<< max_left[i]<<" ";
    }
    // cout<<endl;

    int minimum = INT_MAX;
    for( int i = size - 1; i >= 0; i-- )
    {
        minimum = min( minimum, A[i] );
        min_right[i] = minimum;
        // cout<<"min_right["<<i<<"] = " << min_right[i] <<endl;
    }

    for( int hole = 1; pole < size - 1 ; pole++ )
    {
        if( max_left[pole] <= min_right[pole] )
        {
            return pole;
        }
    }

    return -1;
}

int main()
{
    vector<int> A = { 4, 2, 2, 3, 1, 4, 7, 8, 6, 9 };
    vector<int> B = { -2147483646, -2147483647, -2147483646, -2147483647 };
    vector<int> C = { -2, -2 ,3, -2 };
    cout<< solution( C ) << endl;
}
