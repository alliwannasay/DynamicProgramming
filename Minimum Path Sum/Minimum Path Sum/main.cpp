//
//  main.cpp
//  Minimum Path Sum
//
//  Created by zzqmyos on 17/4/28.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
    int m = int(grid.size());
    int n = int(grid[0].size());
    if(m == 0 || n == 0) return 0;
    vector<vector<int>>dp;
    vector<int>tmp;
    tmp.assign(n,0);
    dp.assign(m, tmp);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0) dp[i][j] = grid[i][j];
            else if(i == 0 && j != 0) dp[i][j] = dp[i][j-1]+grid[i][j];
            else if(i != 0 && j == 0) dp[i][j] = dp[i-1][j]+grid[i][j];
            else
            {
                int a = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = grid[i][j]+a;
            }
        }
    }
    return dp[m-1][n-1];
}


int main(int argc, const char * argv[]) {
    int m = 2;
    int n = 2;
    vector<vector<int>>grid;
    vector<int>tmp;
    tmp.assign(n,0);
    grid.assign(m, tmp);
    grid[0][0] = 1;
    grid[0][1] = 2;
    grid[1][0] = 1;
    grid[1][1] = 1;
    cout<<minPathSum(grid)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
