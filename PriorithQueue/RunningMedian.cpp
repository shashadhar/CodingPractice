#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

class MedianHandler
{
public:
    float median;

    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int> left; //max heap

    void push(int number)
    {
        //Complete this method to update median after every insertion
        if (left.empty() and right.empty())
        {
            median = number;
            left.push(number);
        }

        else if (left.size() == right.size())
        {
            if (number <= median)
            {
                left.push(number);
                median = left.top();
            }
            else
            {
                right.push(number);
                median = right.top();
            }
        }
        else if (left.size() > right.size())
        {

            if (number <= median)
            {
                right.push(left.top());
                left.pop();
                left.push(number);
            }
            else
            {
                right.push(number);
            }
            median = (left.top() + right.top()) / 2.0;
        }
        else
        {
            if (number > median)
            {
                left.push(right.top());
                right.pop();
                right.push(number);
            }
            else
            {
                left.push(number);
            }
            median = (left.top() + right.top()) / 2.0;
        }
    }
    float getMedian()
    {
        //Should return the median in O(1) time
        return median;
    }
};

int main()
{
    MedianHandler medianHandler;
    vector<int> runningInputs = {10, 5, 2, 3, 0, 12, 18, 20, 22};
    for (auto s : runningInputs)
    {
        medianHandler.push(s);
        cout << medianHandler.getMedian() << " ";
    }
}