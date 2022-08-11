#include<iostream>
#include<vector>

using namespace std;

/**
 * Vector initialization
 * vector<vector<int>> vec( n , vector<int> (m, 0)); 
 * vector<vector<int>> vec( n , vector<int> (m)); 
 * 
 */
void pascaslTriangle(int n){

    vector<vector<int>> rows(n);
    

    for(int i=0;i<n;i++){
        rows[i].resize(i + 1);
        rows[i][0]=1;
        rows[i][i]=1;

         for(int j=1;j<i;j++){
             rows[i][j]=rows[i-1][j-1] + rows[i-1][j];
         }
    }

    // print 

    for(int i =0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<rows[i][j]<<" ";
        }
        cout<<endl;

    }

}


int main(){
 pascaslTriangle(5);
}