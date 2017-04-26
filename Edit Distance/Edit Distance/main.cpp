//
//  main.cpp
//  Edit Distance
//
//  Created by zzqmyos on 17/4/26.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2) {
    int w1_len = int(word1.length());
    int w2_len = int(word2.length());
    if(w1_len == 0) return w2_len;
    if(w2_len == 0) return w1_len;
    vector<vector<int>>dp;
    dp.resize(w1_len);
    for(int i = 0; i < w1_len; i++)
    {
        dp[i].resize(w2_len);
    }
    if(word1[0] == word2[0]) dp[0][0] = 0;
    else dp[0][0] = 1;
    for(int i = 0; i < w1_len; i++)
    {
        for(int j = 0; j < w2_len; j++)
        {
            if(i == 0 && j == 0) continue;
            else if(word1[i] != word2[j])
            {
                if(i == 0) dp[i][j] = dp[i][j-1]+1;
                else if(j == 0) dp[i][j] = dp[i-1][j]+1;
                else dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
            else if(word1[i] == word2[j])
            {
                if(i == 0) dp[i][j] = min(j,dp[i][j-1]+1);
                else if(j == 0) dp[i][j] = min(i,dp[i-1][j]+1);
                else dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
    }
    return dp[w1_len-1][w2_len-1];
}

//总结：双序列问题套路记住就好。这题前面先塞一个垫底的玩意就没这么麻烦了。

int main(int argc, const char * argv[]) {
    string word1 = "c";
    string word2 = "cab";
    cout<<minDistance(word1, word2)<<endl;
    return 0;
}
