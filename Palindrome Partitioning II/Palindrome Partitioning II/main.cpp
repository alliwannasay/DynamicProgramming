//
//  main.cpp
//  Palindrome Partitioning II
//
//  Created by zzqmyos on 17/3/28.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string s)
{
    int s_len = int(s.size());
    if(s_len == 0)
    {
        return true;
    }
    for(int i = 0; i < s_len/2;i++)
    {
        if(s[i] == s[s_len-1-i]) continue;
        else return false;
    }
    return true;
}

int minCut_1(string s) {//错的
    vector<vector<int>>dp;
    int s_len = int(s.size());
    if(s_len == 0) return 0;
    dp.resize(s_len);
    dp[0].push_back(-1);
    for(int i = 1; i < s_len; i++)
    {
        int lastCutNum = int(dp[i-1].size());
        for(int j = 0; j < lastCutNum; j++)
        {
            int thisCut = dp[i-1][j];
            string tests = s.substr(thisCut+1,i-thisCut);
            if(isPalindrome(tests) == 1)
            {
                dp[i].push_back(thisCut);
                break;
            }
            else
            {
                dp[i].push_back(thisCut);
            }
            if(j == lastCutNum-1) dp[i].push_back(i-1);
            
        }
//        for(int j = 0; j < i;j++)
//        {
//            string tests = s.substr(thisCut+1,i-thisCut);
//        }
    }
    return int(dp[s_len-1].size())-1;
}

int minCut_2(string s)//太长也会 Time Limit Exceeded 回文判断也要dp
{
    vector<int>dp;
    int s_len = int(s.size());
    if(s_len == 0) return 0;
    dp.resize(s_len);
    dp[0] = 0;
    for(int i = 1; i < s_len; i++)
    {
        int minc = s_len;
        for(int j = -1; j < i;j++)
        {
            string tests = s.substr(j+1,i-j);
            if(isPalindrome(tests))
            {
                if(j == -1)
                {
                    minc = 0;
                    break;
                }
                else if(dp[j] + 1 < minc) minc = dp[j] + 1;
            }
        }
        dp[i] = minc;
    }
    return dp[s_len-1];
}

int minCut(string s)
{
    vector<int>dp;
    vector<vector<bool>>state;
    int s_len = int(s.size());
    if(s_len == 0) return 0;
    dp.resize(s_len);
    state.resize(s_len);
    for(int i = 0; i < s_len;i++)
    {
        state[i].resize(s_len);
        state[i][i] = true;
        
    }
    state[0][0] = true;
    dp[0] = 0;
    
    for(int i = 1; i < s_len; i++)
    {
        int minc = s_len;
        for(int j = -1; j < i;j++)
        {
            if(j+2 > i-1)
            {
                if(s[j+1] == s[i])
                {
                    state[j+1][i] = true;
                }
            }
            else if(state[j+2][i-1] == true && s[j+1] == s[i])
            {
                state[j+1][i] = true;
            }
            else state[j+1][i] = false;
            
            if(state[j+1][i])
            {
                if(j == -1)
                {
                    minc = 0;
                    break;
                }
                else if(dp[j] + 1 < minc) minc = dp[j] + 1;
            }
        }
        dp[i] = minc;
    }
    return dp[s_len-1];
}

//总结：第1个版本错在下一步的minc并不只是依赖于上一步的分割，有可能把上一步分割打破了
//所以这种情况的dp就需要二维dp，两边拓展
//以及，要注意回文也可以dp



int main(int argc, const char * argv[]) {
    string s = "fff";
    bool isP = isPalindrome(s);
    std::cout << "isP:" << isP << "\n";
    int result = minCut(s);
    std::cout << result << "\n";
    return 0;
}
