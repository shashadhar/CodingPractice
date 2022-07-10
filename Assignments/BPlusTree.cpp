/* C++ Program to implement B-Tree using Class using Linked Lists */

#include <iostream>
#include <stdlib.h>

using namespace std;
const int MAX = 4 ;
const int MIN = 2 ;

struct keyValue{
        int key;
        int value;
        public:
        keyValue(){
                key=0;
                value=0;
        }
       
};

struct btnode
{
        int count ;
        keyValue value[MAX + 1] ;
        btnode *child[MAX + 1] ;
} ;

class btree
{
        private :
                btnode *root ;
        public :
                btree( ) ;
                void insert ( keyValue val ) ;
                int setval ( keyValue val, btnode *n, keyValue *p, btnode **c ) ;
                static btnode * search ( keyValue val, btnode *root, int *pos ) ;
                static int searchnode ( keyValue val, btnode *n, int *pos ) ;
                void fillnode ( keyValue val, btnode *c, btnode *n, int k ) ;
                void split ( keyValue val, btnode *c, btnode *n,
                                int k, keyValue *y, btnode **newnode ) ;
                void del ( keyValue val ) ;
                int delhelp ( keyValue val, btnode *root ) ;
                void clear ( btnode *root, int k ) ;
                void copysucc ( btnode *root, int i ) ;
                void restore ( btnode *root, int i ) ;
                void rightshift ( int k ) ;
                void leftshift ( int k ) ;
                void merge ( int k ) ;
                void show( ) ;
                static void display ( btnode *root ) ;
                static void deltree ( btnode *root ) ;
                ~btree( ) ;
} ;

btree :: btree( )
{
        root = NULL ;
}
void btree :: insert ( keyValue val )
{
        keyValue i ;
        btnode *c, *n ;
        int flag ;
        flag = setval ( val, root, &i, &c ) ;
        if ( flag )
        {
                n = new btnode ;
                n -> count = 1 ;
                n -> value[1] = i ;
                n -> child[0] = root ;
                n -> child[1] = c ;
                root = n ;
        }
}
int btree :: setval ( keyValue val, btnode *n, keyValue *p, btnode **c )
{
        int k ;
        if ( n == NULL )
        {
                *p = val ;
                *c = NULL ;
                return 1 ;
        }
        else
        {
                if ( searchnode ( val, n, &k ) )
                        cout << endl << "Key value already exists." << endl ;
                if ( setval ( val, n -> child[k], p, c ) )
                {
                        if ( n -> count < MAX )
                        {
                                fillnode ( *p, *c, n, k ) ;
                                return 0 ;
                        }
                        else
                        {
                                split ( *p, *c, n, k, p, c ) ;
                                return 1 ;
                        }
                }
                return 0 ;
        }
}
btnode * btree :: search ( keyValue val, btnode *root, int *pos )
{
        if ( root == NULL )
                return NULL ;
        else
        {
                if ( searchnode ( val, root, pos ) )
                        return root ;
                else
                        return search ( val, root -> child[*pos], pos ) ;
        }
}
int btree :: searchnode ( keyValue val, btnode *n, int *pos )
{
        if ( val.key < n -> value[1].key )
        {
                *pos = 0 ;
                return 0 ;
        }
        else
        {
                *pos = n -> count ;
                while ( ( val.key < n -> value[*pos].key ) && *pos > 1 )
                        ( *pos )-- ;
                if ( val.key == n -> value[*pos].key )
                        return 1 ;
                else
                        return 0 ;
        }
}
void btree :: fillnode ( keyValue val, btnode *c, btnode *n, int k )
{
        int i ;
        for ( i = n -> count ; i > k ; i-- )
        {
                n -> value[i + 1] = n -> value[i] ;
                n -> child[i + 1] = n -> child[i] ;
        }
        n -> value[k + 1] = val ;
        n -> child[k + 1] = c ;
        n -> count++ ;
}
void btree :: split ( keyValue val, btnode *c, btnode *n,
                int k, keyValue *y, btnode **newnode )
{
        int i, mid ;

        if ( k <= MIN )
                mid = MIN ;
        else
                mid = MIN + 1 ;

        *newnode = new btnode ;

        for ( i = mid + 1 ; i <= MAX ; i++ )
        {
                ( *newnode ) -> value[i - mid] = n -> value[i] ;
                ( *newnode ) -> child[i - mid] = n -> child[i] ;
        }

        ( *newnode ) -> count = MAX - mid ;
        n -> count = mid ;

        if ( k <= MIN )
                fillnode ( val, c, n, k ) ;
        else
                fillnode ( val, c, *newnode, k - mid ) ;

        y->key =  n->value[n -> count].key;
        y->value =  n->value[n -> count].value;
        ( *newnode ) -> child[0] = n -> child[n -> count] ;
        n -> count-- ;
}
void btree :: del ( keyValue val )
{
        btnode * temp ;

        if ( ! delhelp ( val, root ) )
                cout << endl << "Value " << val.key << " not found." ;
        else
        {
                if ( root -> count == 0 )
                {
                        temp = root ;
                        root = root -> child[0] ;
                        delete temp ;
                }
        }
}
int btree :: delhelp ( keyValue val, btnode *root )
{
        int i ;
        int flag ;

        if ( root == NULL )
                return 0 ;
        else
        {
                flag = searchnode ( val, root, &i ) ;
                if ( flag )
                {
                        if ( root -> child[i - 1] )
                        {
                                copysucc ( root, i ) ;
                                flag = delhelp ( root -> value[i], root -> child[i] ) ;
                                if ( !flag )
                                        cout << endl << "Value " << val.key << " not found." ;
                        }
                        else
                                clear ( root, i ) ;
                }
                else
                        flag = delhelp ( val, root -> child[i] ) ;
                if ( root -> child[i] != NULL )
                {
                        if ( root -> child[i] -> count < MIN )
                                restore ( root, i ) ;
                }
                return flag ;
        }
}
void btree :: clear ( btnode *root, int k )
{
        int i ;
        for ( i = k + 1 ; i <= root -> count ; i++ )
        {
                root -> value[i - 1] = root -> value[i] ;
                root -> child[i - 1] = root -> child[i] ;
        }
        root -> count-- ;
}
void btree :: copysucc ( btnode *root, int i )
{
        btnode *temp = root -> child[i] ;

        while ( temp -> child[0] )
                temp = temp -> child[0] ;

        root -> value[i] = temp -> value[1] ;
}
void btree :: restore ( btnode *root, int i )
{
        if ( i == 0 )
        {
                if ( root -> child [1] -> count > MIN )
                        leftshift ( 1 ) ;
                else
                        merge ( 1 ) ;
        }
        else
        {
                if ( i == root -> count )
                {
                        if ( root -> child[i - 1] -> count > MIN )
                                rightshift ( i ) ;
                        else
                                merge ( i ) ;
                }
                else
                {
                        if ( root -> child[i - 1] -> count > MIN )
                                rightshift ( i ) ;
                        else
                        {
                                if ( root -> child[i + 1] -> count > MIN )
                                        leftshift ( i + 1 ) ;
                                else
                                        merge ( i ) ;
                        }
                }
        }
}
void btree :: rightshift ( int k )
{
        int i ;
        btnode *temp ;

        temp = root -> child[k] ;

        for ( i = temp -> count ; i > 0 ; i-- )
        {
                temp -> value[i + 1] = temp -> value[i] ;
                temp -> child[i + 1] = temp -> child[i] ;
        }

        temp -> child[1] = temp -> child[0] ;
        temp -> count++ ;
        temp -> value[1] = root -> value[k] ;
        temp = root -> child[k - 1] ;
        root -> value[k] = temp -> value[temp -> count] ;
        root -> child[k] -> child [0] = temp -> child[temp -> count] ;
        temp -> count-- ;
}
void btree :: leftshift ( int k )
{
        btnode *temp ;

        temp = root -> child[k - 1] ;
        temp -> count++ ;
        temp -> value[temp -> count] = root -> value[k] ;
        temp -> child[temp -> count] = root -> child[k] -> child[0] ;
        temp = root -> child[k] ;
        root -> value[k] = temp -> value[1] ;
        temp -> child[0] = temp -> child[1] ;
        temp -> count-- ;
        for ( int i = 1 ; i <= temp -> count ; i++ )
        {
                temp -> value[i] = temp -> value[i + 1] ;
                temp -> child[i] = temp -> child[i + 1] ;
        }
}
void btree :: merge ( int k )
{
        btnode *temp1, *temp2 ;
        temp1 = root -> child[k] ;
        temp2 = root -> child[k - 1] ;
        temp2 -> count++ ;
        temp2 -> value[temp2 -> count] = root -> value[k] ;
        temp2 -> child[temp2 -> count] = root -> child[0] ;
        for ( int i = 1 ; i <= temp1 -> count ; i++ )
        {
                temp2 -> count++ ;
                temp2 -> value[temp2 -> count] = temp1 -> value[i] ;
                temp2 -> child[temp2 -> count] = temp1 -> child[i] ;
        }
        for ( int i = k ; i < root -> count ; i++ )
        {
                root -> value[i] = root -> value[i + 1] ;
                root -> child[i] = root -> child[i + 1] ;
        }
        root -> count-- ;
        delete temp1 ;
}
void btree :: show( )
{
        display ( root ) ;
}
void btree :: display ( btnode *root )
{
    int i=0;
        if ( root != NULL )
        {
                for ( i = 0 ; i < root -> count ; i++ )
                {
                        display ( root -> child[i] ) ;
                        cout << root -> value[i + 1].key << "\t" ;
                }
                display ( root -> child[i] ) ;
        }
}
void btree :: deltree ( btnode *root )
{
    int i=0;
        if ( root != NULL )
        {
                for (i = 0 ; i < root -> count ; i++ )
                {
                        deltree ( root -> child[i] ) ;
                        delete ( root -> child[i] ) ;
                }
                deltree ( root -> child[i] ) ;
                delete ( root -> child[i] ) ;
        }
}

btree :: ~btree( )
{
        deltree ( root ) ;
}
