 
#include <iostream>
#include "BPlusTree.cpp"

void print_bool(bool cond) {
    if (cond) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }
}

 int main() {
    btree b ;
    int arr[ ] = { 27, 1, 22, 47, 32, 10, 9, 7, 13 } ;
        int sz = sizeof ( arr ) / sizeof ( int ) ;

        for ( int i = 0 ; i < sz ; i++ ){
                keyValue k;
                k.key=arr[i];
                k.value=i;
                b.insert (k) ;
        }
        cout << "B-tree of order 5:" << endl ;

        b.show( ) ;
        keyValue k;
        k.key=22;
        k.value=0;
        b.del ( k ) ;
       // b.del ( 11 ) ;

        cout << "\n\nB-tree after deletion of values:" << endl ;
        b.show( ) ;

        cout<<"\n";
        return 0;
 }