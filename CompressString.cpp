 /*
 Implement a method to perform basic string compression using the counts
 of repeated characters. For example, the sstring aabcccccaaa would become
 a2b1c5a3. If the "compressed" string would not become smaller than the original
 string your method should return the original string.
 */

#include <iostream>
#include <string>

using namespace std;

std::string compress(std::string str ) {
    
    int strlen = (int)str.size();
    
    if( strlen == 0 )
    {
        return str;
    }
    
    std::string compressed = "";
    char previous = str[0]; // initialize first character of the string
    compressed += str[0];
    
    int count = 1;
    
    for( int i = 1; i < strlen; i++ )
    {
        if( str[i] == previous )
        {
            count++;
        }
        else
        {
            compressed += to_string( count );
            compressed += str[i];
            previous = str[i];
            count = 1;
        }
        
        if( (int)compressed.size() > strlen )
        {
            return str; // return if larger than the original string
        }
    }
    
    if( count != 0 ) // ex. bbb
    {
        compressed += to_string(count);
    }
    
    if( compressed.size() > str.size() )
    {
        return str;
    }
    else
    {
        return compressed;
    }
}

int main()
{
    string str;
    cin>> str;
    cout << compress( str );

    return 0;
}
