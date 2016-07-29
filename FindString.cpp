#include <iostream>
#include <algorithm>
#define NUM 7

using namespace std;

bool foundStringBinary( string array[], int size, string target );
bool foundStringIter( string array[], int size, string target );

int main()
{
    string array[NUM] = { "abc", "def", "aaa", "flora", "choco", "llll", "zzz" };
    
    if( foundStringBinary( array, NUM, "aaa" ) )
    {
        cout<<"found!"<<endl;
    }
    else
    {
        cout<<"not found!"<<endl;
    }
    
    
    if( foundStringIter( array, NUM, "llll" ) )
    {
        cout<<"found!"<<endl;
    }
    else
    {
        cout<<"not found!"<<endl;
    }

    if( binary_search( array, array + NUM, "aaa") ) // library
    {
        cout<<"found!"<<endl;
    }
    else
    {
        cout<<"not found!"<<endl;
    }
}

bool foundStringBinary( string array[], int size, string target )
{
    sort( array, array+size ); // sort the array
    
    int mid;
    int left = 0, right = size-1;
    int count = 0;
    
    while( left <= right )
    {
        ++count;
        
        mid = ( left + right ) / 2;
        
        if( target == array[mid] )
        {
            cout<< "binary search: " << count << endl;
            return true;
        }
        
        if( target < array[mid] )
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return false;
}

bool foundStringIter( string array[], int size, string target )
{
    for( int i = 0; i < size; i++ )
    {
        if( array[i] == target )
        {
            cout << "iter :" << i + 1 << endl;
            return true;
        }
    }

    return false;
}
