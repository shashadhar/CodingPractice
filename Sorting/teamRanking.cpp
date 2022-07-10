#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int badness(vector<pair<string,int> > teams){
    //Complete this function to return the min badness
    int n = teams.size();
    //create a count array init with 0
    vector<int> cnt(n+1,0);
    
    
    for(int i=0;i<n;i++){
        cnt[teams[i].second]++;
    }
    
    int pos = 1;
    int sum = 0;
    for(int i=1;i<=n;i++){
        while(cnt[i]){
            sum += abs(pos-i);
            cnt[i]--;
            pos++;
        }
    }
       
    return sum;
}

// every team will put its preferred rank and we have to calculate the minimum sum
// for difference between preferred rank and assigned rank

int main()
{
    vector<pair<string ,int >> teams {
     {"winOrBooze",1},
     {"Ball of duty",2},
     {"Who knows",2},
     {"Bhole",1},
     {"Decoders",5},
     {"stranges",6}
    };

   cout<<badness(teams);
    
}
