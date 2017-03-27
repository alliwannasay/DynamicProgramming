//
//  main.cpp
//  Word Break
//
//  Created by zzqmyos on 17/3/26.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    bool* dp = new bool[s.length()];
    for(int i = 0; i < s.length();i++)
    {
        dp[i] = 0;
    }
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = -1; j <= i - 1; j++)
        {
            if(dp[j] == 1 || j == -1)
            {
                string remain = s.substr(j+1,i-j);
                
                if(find(wordDict.begin(),wordDict.end(),remain)!= wordDict.end())
                {
                    dp[i] = 1;
                }
            }
        }
    }
    bool result = dp[s.length()-1];
    delete [] dp;
    return result;
}

int main(int argc, const char * argv[]) {
    string s = "leetcode";
    vector<string> dict;
    dict.push_back("leet");
    dict.push_back("code");
    cout << wordBreak(s,dict) << "\n";
    return 0;
}


