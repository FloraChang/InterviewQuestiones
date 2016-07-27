/*
 A binary tree T is given. A node of tree T containing value V is described as visible if the path from the root of the tree 
 to that node does not contain a node with any value exceeding V. In particular, the root is always visible and nodes with 
 values lower than that of the root are never visible.
 
 Write a function:
    int solution(tree* T);
 that,given a binary tree T consisting of Nodes, returns its number of visible nodes.
 */

#include <iostream>
using namespace std;

struct tree {
    int x;
    tree * l;
    tree * r;
};

tree* root = NULL;

void insertNode( int data )
{
    tree* parent;
    tree* current;
    
    tree* newNode = new tree();
    newNode->x = data;
    
    if( root == NULL )
    {
        // cout<< newNode->x << " is inserted as a root."<<endl;
        root = newNode;
        return;
    }
    
    current = root;
    
    while( true )
    {
        parent = current;
        
        if( data < parent->x )
        {
            current = current->l;
            if( current == NULL )
            {
                // cout<< newNode->x << " is inserted under "<<parent->x<<" on the left."<<endl;
                parent->l = newNode;
                break;
            }
        }
        else if( data > parent->x )
        {
            current = current->r;
            if( current == NULL )
            {
                // cout<< newNode->x << " is inserted under "<<parent->x<<" on the right."<<endl;
                parent->r = newNode;
                break;
            }
        }
    }
}

int visbleNumber( tree *T, int maximum )
{
    int num = 0;
    
    if( T == NULL )
    {
        return num;
    }
    
    // compare the value with current maximum in this path
    if( T->x >= maximum )
    {
        num = 1;
        maximum = T->x;
    }
    
    return num + visbleNumber( T->l, maximum ) + visbleNumber( T->r, maximum );
}

int solution(tree * T)
{
    return visbleNumber( T, -100001 ) ;
}

void visbleNumber2( tree *T, int maximum, int& count )
{
    if( T == NULL )
    {
        return;
    }
    
    // compare the value with current maximum in this path
    if( T->x >= maximum )
    {
        maximum = T->x;
        count++;
    }
    
    visbleNumber2( T->l, maximum, count );
    visbleNumber2( T->r, maximum, count );
}

int solution2(tree * T)
{
    int visibleNum = 0;
    visbleNumber2( root, -100001, visibleNum );
    return visibleNum;
}

int main()
{
    insertNode(5);
    insertNode(3);
    insertNode(10);
    insertNode(79);

    // method 1
    cout<< solution( root ) << endl; // 3
    
    // method 2
    cout<< solution2( root ) << endl;
}
