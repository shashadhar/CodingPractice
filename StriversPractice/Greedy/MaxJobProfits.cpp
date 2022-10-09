#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <unordered_map>
#include <string>
#include <set>
#include <map>

using namespace std;

class Job
{
public:
  int pos;
  int deadline;
  int profit;

  Job(int p, int d, int pr){
    pos = p;
    deadline = d;
    profit = pr;
  }
};

bool compare(Job j1, Job j2)
{
  if (j1.profit > j2.profit)
  {
    return true;
  }
  if (j1.pos < j2.pos)
  {
    return true;
  }
  return false;
}

pair<int, int> maxProfit(vector<Job> jobs, int n)
{

  sort(jobs.begin(), jobs.end(), compare);

  // get maxdeadline
  int maxdeadLine = jobs[0].deadline;
  for (int i = 1; i < n; i++)
  {
    maxdeadLine = max(maxdeadLine, jobs[i].deadline);
  }

  // declare an array to keep track of deadline
  vector<int> slots(maxdeadLine, -1);

  // get the profits and assign to the deadline
  int profits = 0;
  int noOfJobs =0;
  for (int i = 0; i < n; i++)
  {

    for (int j = jobs[i].deadline; j >= 1; j--)
    {
      if(slots[j] ==-1){
        slots[j] = i;
         profits = profits + jobs[i].profit;
         noOfJobs ++;
         break;
      }

    }
  }

 return {noOfJobs, profits}; 
}

/*
You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

Examples

Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60

Example 2:

Input: N = 5, Jobs = {(1,2,100),(2,1,19),(3,2,27),(4,1,25),(5,1,15)}

Output: 2 127

Explanation: The  first and third job both having a deadline 2 give the highest profit.
Profit = 100 + 27 = 127
*/

int main()
{
  Job j1(1,4,20);
  Job j2(2,1,10);
  Job j3(3,1,40);
  Job j4(4,1,30);
  vector<Job> jobs = {j1,j2,j3,j4};
  pair<int,int> p = maxProfit(jobs, 4);
  cout<< "Max profit:"<<p.second << " Jobs:"<< p.first; 

}