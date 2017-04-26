//
//  main.cpp
//  Distinct Subsequences
//
//  Created by zzqmyos on 17/4/26.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDistinct(string s, string t) {
    int s_len = int(s.length());
    int t_len = int(t.length());
    if(s_len == 0) return 0;
    if(t_len == 0) return 0;
    vector<vector<int>>dp;
    dp.resize(s_len);
    for(int i = 0; i < s_len; i++)
    {
        dp[i].resize(t_len);
    }
    if(s[0] == t[0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    for(int i = 0; i < s_len; i++)
    {
        for(int j = 0; j < t_len; j++)
        {
            if(i == 0 && j == 0) continue;
            else if(j > i)
            {
                dp[i][j] = 0;
                continue;
            }
            else if(s[i] == t[j])
            {
                if(j != 0) dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j] + 1;
            }
            else if(s[i] != t[j])
            {
                if(j != 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[s_len-1][t_len-1];
}

//总结：为什么这道题可以用动归：可分解为子问题，原问题的最优解可以划归为子问题的最优解

int main(int argc, const char * argv[]) {
    string s = "rabbbit";
    string t = "rabbit";
    cout<<numDistinct(s, t)<<endl;
    return 0;
}
