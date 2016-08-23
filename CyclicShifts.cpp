#include <algorithm>
#include <iostream>

using namespace std;

int solution ( int n ) {
    unsigned long maximum = n; // initial
    unsigned long num = n;
    
    int shift = 0;
    
    for( int i = 1; i < 30; i++ )
    {
        num = ( n >> i ) | ( n << ( 30 - i ) & 0x3FFFFFFF );
        // cout<<i<< ". " << num<<endl;
        if( num > maximum )
        {
            maximum = num;
            shift = i;
        }
    }
    return shift;
}

int main() {
    
    cout << solution( 9736 ) << endl; // 11
    
    return 0;
}
