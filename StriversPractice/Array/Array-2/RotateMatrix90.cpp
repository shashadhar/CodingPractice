#include<iostream>
#include<vector>

using namespace std;

void rotateBy90(vector<vector<int>> &mat){

 int n = mat.size();
 for(int i= 0 ; i< n; i++){
    for(int j=0; j< i; j++){
        swap(mat[i][j],mat[j][i]);
    }
 }

 // reverse the array
 for(int i = 0 ; i< n; i++){
     reverse(mat[i].begin(),mat[i].end());
 }

     
}


/**
 * Rotate array by 90
 *  we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, 
 * so that’s why we transpose the matrix and then reverse each row, and since we are making 
 * changes in the matrix itself space complexity gets reduced to O(1).
 * 
 * Input: [[1,2,3],
 *         [4,5,6],
 *         [7,8,9]]
 * Output: [[7,4,1],
 *          [8,5,2],
 *          [9,6,3]]
 * 
 */
int main(){
vector<vector<int>> mat = {
                           {1,2,3},
                           {4,5,6},
                           {7,8,9}
                           };

cout<<" Original matrix" ;
cout<< endl;
for(int i = 0; i< mat.size(); i++){
   for(int j = 0 ; j< mat.size(); j++){
       cout<< mat[i][j]<< " ";
   }
   cout<< endl;
}

cout<<" Rotated matrix" ;
cout<< endl;
rotateBy90(mat);
for(int i = 0; i< mat.size(); i++){
   for(int j = 0 ; j< mat.size(); j++){
       cout<< mat[i][j]<< " ";
   }
   cout<< endl;
}

}



