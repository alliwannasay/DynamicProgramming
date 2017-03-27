//
//  main.cpp
//  Traingle
//
//  Created by zzqmyos on 17/3/27.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minimumTotal_1(vector<vector<int>>& triangle) {//DP from up to bottom
    int row_num = int(triangle.size());
    vector<vector<int>>dp;
    dp.resize(row_num);
    dp[0].push_back(triangle[0][0]);
    for(int i = 1; i < row_num; i++)
    {
        int col_num = int(triangle[i].size());
        dp[i].resize(col_num);
        for(int j = 0; j < col_num;j++)
        {
            if(j == 0)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }
            else if(j == col_num - 1)
            {
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = triangle[i][j] + min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int last_col_num = int(dp[row_num-1].size());
    int result = dp[row_num-1][0];
    for(int i = 1; i < last_col_num; i++)
    {
        if(dp[row_num-1][i] < result)
        {
            result = dp[row_num-1][i];
        }
    }
    return result;
}

int minimumTotal(vector<vector<int>>& triangle)//DP from bottom to up
{
    int row_num = int(triangle.size());
    vector<int>dp(triangle.back());
    for(int i = row_num - 2; i >= 0; i--)
    {
        int col_num = i + 1;
        for(int j = 0; j < col_num; j++)
        {
            dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
        }
    }
    return dp[0];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>>dp;
    vector<int>temp;
    
    temp.push_back(2);
    dp.push_back(temp);
    temp.clear();
    
    temp.push_back(3);
    temp.push_back(4);
    dp.push_back(temp);
    temp.clear();
    
    temp.push_back(6);
    temp.push_back(5);
    temp.push_back(7);
    dp.push_back(temp);
    temp.clear();
    
    temp.push_back(4);
    temp.push_back(1);
    temp.push_back(8);
    temp.push_back(3);
    dp.push_back(temp);
    temp.clear();
    
    int result = minimumTotal(dp);
    
    std::cout << result << "\n";
    return 0;
}
