#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

class Car
{
public:
    string id;
    int x, y;
    Car(string id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int distance()
    {
        return x * x + y * y;
    }
};

class Compare
{
public:
    bool operator()(Car a, Car b)
    {

        return a.distance() < b.distance();
    }
};

void getNearestCars(vector<Car> cars, int k)
{
    priority_queue<Car, vector<Car>, Compare> maxheap(cars.begin(), cars.begin() + k);

    for (int i = k; i < cars.size(); i++)
    {
        Car maxCarInQueue = maxheap.top();
        if (maxCarInQueue.distance() > cars[i].distance())
        {
            maxheap.pop();
            maxheap.push(cars[i]);
        }
    }

    // print the k nearest cars
    while (!maxheap.empty())
    {
        cout << maxheap.top().id;
        maxheap.pop();
    }
}

int main()
{

    Car c1("c1", 1, 1);

    Car c2("c2", 2, 1);

    Car c3("c3", 3, 2);

    Car c4("c4", 0, 1);

    Car c5("c5", 2, 3);

    vector<Car> cars = {c1, c2, c3, c4, c5};
    getNearestCars(cars, 3);
}