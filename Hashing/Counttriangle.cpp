#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include<unordered_map>
#include <string>
#include<set>

using namespace std;

class Point{
public :
int x;
int y;
Point(int x,int y){
    this->x = x;
    this->y = y;
}
};

class Compare {
    public:
bool operator() (const Point p1, const Point p2){
    if(p1.x == p2.x){
       return p1.y > p2.y;
    }else{
       return  p1.x > p2.x;
    }
}
};

int countTriangle(vector<Point> arr){
    unordered_map <int,int> mapX;
    unordered_map <int,int> mapY;
    for(auto s : arr){
        mapX[s.x]++;
        mapY[s.y]++;
    }

    int total = 0;
    for(auto s: arr){
        int totalxPoints = mapX[s.x];
        int totalyPoints = mapY[s.y];
        total = total + ((totalxPoints-1) * (totalyPoints -1));
        
    }
    return total;
}

// Count no of rectangle parallet to x and y axis
// a/r, a , ar
int main()
{
    Point p1 (4,1);
    Point p2 (4,0);
    Point p3 (0,0);
    Point p4 (0,1);

    Point p5 (1,1);
    Point p6 (1,0);
    Point p7 (2,0);
    Point p8 (2,1);

    vector<Point> arr={p1,p2,p3,p4,p5,p6,p7,p8};
    cout<<countTriangle(arr);

}