#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Item {
    public:
    int weight;
    int value;
    Item(int v, int w){
        weight = w;
        value = v;
    }
};

bool compare(Item i1, Item i2){
  return ((double)i1.value/i1.weight) > ((double)i2.value / i2.weight); 
}

int fracKnapsack(vector<Item> items, int n,int w){
    
    // sort by profit/weight value
    sort(items.begin(), items.end(),compare);
    
    double profit =0;
    int remainWt = w;
    for(int i =0 ;i<n; i++){
        
        if(remainWt >= items[i].weight){
            profit = profit + items[i].value;
            remainWt = remainWt - items[i].weight;
        }else{
            // get the fractiion part profit as per the remain weight value
            profit = profit + (((double)items[i].value / items[i].weight) * remainWt); 
        }

    }
 return profit;
}


/*The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.

Example:

Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.

Output: 240.00

Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00

*/

int main(){
   int n = 3, weight = 50;
   Item t1 (100,20);
   Item t2 (60,10);
   Item t3(120,30);
   vector<Item> items = { t1,t2,t3};
   cout<< "Profit" << fracKnapsack(items,n,weight);


}