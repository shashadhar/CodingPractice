#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(vector<int> b1 , vector<int> b2){
    return b1[2] < b2[2];

}

bool canPlace(vector<int> b1 , vector<int>b2){
   return (b1[0] < b2[0]) &&  (b1[1] < b2[1]) && (b1[2] < b2[2]);
}

/** we need to find the max height achieved so that we can stack 
* one box on top of another when bottom box has more width,depth,height
*{width,depth,height}**/
int maxHeight(vector<vector<int>> boxes){

    sort(boxes.begin(),boxes.end(),compare);
    int n = boxes.size();

    vector<int> dp(n+1,0);
    
    for(int i =0 ; i<n;i++){
        dp[i]= boxes[i][2];
    }

    int height =boxes[0][2];
    for(int i =1;i<n;i++){
        for(int j=0;j<i;j++){
            if(canPlace(boxes[j],boxes[i])){
                dp[i]= max(dp[i],boxes[i][2]+dp[j]);
                height = max(height, dp[i]);
            }
        }
    }
    return height;
}

int LIS(vector<int> arr,int n){
    if(n == 0){
        return 1;
    }
    int ans = 1;
    for (int i = n - 1; i>=0; i--){
    if (arr[i] < arr[n]){
      ans = max(ans, 1 + LIS(arr, i));
    }
    }
    return ans;
}

int lisRec(vector<int> arr, int n){
  int max_ans = 1;
  for (int i = 0;i<n;i++){
    max_ans = max(max_ans, LIS(arr, i));
  }
  return max_ans;
}


// we need to find the max height achieved so that we can stack 
// one box on top of another when bottom box has more width,depth,height
//{width,depth,height}

int main(){
    vector<vector<int>> boxes= {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5}
    };
    cout<<"maxheight:"<<maxHeight(boxes);
   
}