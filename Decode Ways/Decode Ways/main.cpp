//
//  main.cpp
//  Decode Ways
//
//  Created by zzqmyos on 17/3/28.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int numDecodings(string s) {
    vector<int>dp;
    if(s[0] == '0') return 0;
    int s_len = int(s.size());
    if(s_len == 0) return 0;
    dp.resize(s_len);
    dp[0] = 1;
    
    
    int first = 0;
    stringstream stream(s.substr(0,2));
    stream>>first;
    if(first <= 26 && first != 20 && first != 10) dp[1] = 2;
    else if(first == 20 || first == 10) dp[1] = 1;
    else if(s[0] >= '3' && s[1] == '0') return 0;
    else dp[1] = 1;
    for(int i = 2; i < s_len; i++)
    {
        if(s[i] == '0')
        {
            if(s[i-1] >= '3' || s[i-1] == '0') return 0;
            int beforeTimes = dp[i-2];
            int totalTimes = beforeTimes;
            dp[i] = totalTimes;
        }
        else if(s[i-1] == '0')
        {
            dp[i] = dp[i-1];
        }
        else
        {
            int lastTimes = dp[i-1];
            int beforeTimes = 0;
            int temp = 0;
            stringstream stream(s.substr(i-1,2));
            stream>>temp;
            if(temp <= 26)
            {
                beforeTimes = dp[i-2];
            }
            int totalTimes = lastTimes + beforeTimes;
            dp[i] = totalTimes;
        }
        
    }
    return dp[s_len - 1];
}

//总结：dp倒是好做，这个0的事不想清楚可不行＝＝

int main(int argc, const char * argv[]) {
    int result = numDecodings("27");
    cout<<result;
    std::cout << "\n";
    return 0;
}
