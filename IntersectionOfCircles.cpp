/*
  Calculate the area of intersection between two circles, 
 which are ( x1, y1 ) with radius r1 and ( x2, y2 ) with radius r2.
 */

#include <iostream>
#include <math.h>

using namespace std;

double solution(int x1, int y1, int r1, int x2, int y2, int r2) {
    
    const double PI = 3.141592653589793;
    double r = min( r1, r2 );
    double R = max( r1, r2 );
    double d = sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
    
    cout <<"r = "<<r<<", R = "<<R<<", d = "<<d<<endl;
    
    if( r + R <= d ) // no intersection
    {
        return 0;
    }
    else if( R - r - d >= 0 ) // circle r is inculded in circle R
    {
        return r * r * PI;
    }
    
    double sector1 = r * r * acos( ( d * d + r * r - R * R ) / ( 2 * d * r ) ); // Law of cosine
    double sector2 = R * R * acos( ( d * d + R * R - r * r ) / ( 2 * d * R ) ); // Law of cosine
    double polygon = 0.5 * sqrt( ( -d + r + R ) * ( d + r - R ) * ( d - r + R ) * ( d + r + R ) ); // Heron's formula
    
    return sector1 + sector2 - polygon;
}

int main()
{
    cout<< solution( 0,0,10,0,2,5 ) << endl;
    cout<< solution( 0,0,10,0,5,10 ) << endl;
}
