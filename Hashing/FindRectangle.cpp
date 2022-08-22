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

int getRectangle(vector<Point> arr){
    set<Point,Compare> points;
    for(auto s : arr){
        points.insert(s);
    }

    int total = 0;
    for(auto it = arr.begin(); it!= prev(arr.end()); it++){
        for(auto jt = next(it); jt!= arr.end(); jt++){
            Point p1 = *it;
            Point p2 = *jt;
            if(p1.x == p2.x || p1.y == p2.y){
                continue;
            }

            // get the next two points
            Point p3(p1.x,p2.y);
            Point p4 (p2.x,p1.y); 
            if(points.find(p3)!= points.end() && points.find(p4)!= points.end()){
                total = total+1;
            }
        }

    }
  return total/2;  
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
    cout<<getRectangle(arr);

}