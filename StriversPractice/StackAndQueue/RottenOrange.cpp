#include <bits/stdc++.h>

using namespace std;

int rottenEgg(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid.size();
    int total_rotten = 0;
    int fresh = 0;
    int minutes = 0;

    queue<pair<int, int>> eggQueue;

    // get total rotten eggs
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
            {
                fresh = fresh + 1;
            }
            if (grid[i][j] == 2)
            {
                eggQueue.push({i, j});
            }
        }
    }

    //  up down right left
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!eggQueue.empty())
    {
        int k = eggQueue.size();
        total_rotten = total_rotten + k;
        while (k--)
        {
            auto popedNode = eggQueue.front();
            eggQueue.pop();
            //  check all the neighbour cell and push
            for (int i = 0; i < 4; i++)
            {
                int x = popedNode.first + dx[i];
                int y = popedNode.second + dy[i];

                if ((x >= 0 && x < m) && (y >= 0 && y < n))
                {
                    if (grid[x][y] == 1)
                    {
                        
                        eggQueue.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }

        if (!eggQueue.empty())
        {
            minutes = minutes + 1;
        }
    }

    if (total_rotten == fresh)
    {
        return minutes;
    }
    else
    {
        return -1;
    }
}

int main()
{

    vector<vector<int>> v{{2, 1, 1}, 
                         {1, 1, 0}, 
                         {0, 1, 1}};
    int rotting = rottenEgg(v);
    cout << "Minimum Number of Minutes Required " << rotting << endl;
}