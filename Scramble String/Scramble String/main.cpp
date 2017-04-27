//
//  main.cpp
//  Scramble String
//
//  Created by zzqmyos on 17/4/27.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

bool isScramble(string s1, string s2) {
    int s1_len = int(s1.length());
    int s2_len = int(s2.length());
    if(s1 == s2) return true;
    if(s1_len == 0 || s2_len == 0) return false;
    bool ***dp;
    dp = new bool**[s1_len];
    for(int i = 0; i < s1_len; i++)
    {
        dp[i] = new bool*[s1_len];
        for(int j = 0; j < s1_len; j++)
        {
            dp[i][j] = new bool[s2_len];
        }
    }
    for(int l = 0; l <= s1_len; l++)
    {
        for(int x = 0; x < s1_len;x++)
        {
            for(int y = 0; y < s1_len; y++)
            {
                for(int z = 0; z < s2_len; z++)
                {
                    if(y - x + 1 != l) continue;
                    else if(z+y-x >= s2_len)
                    {
                        dp[x][y][z] = false;
                    }
                    else if(y < x)
                    {
                        dp[x][y][z] = false;
                    }
                    else if(x == y)
                    {
                        if(s1[x] == s2[z]) dp[x][y][z] = true;
                        else if(s1[x] != s2[z]) dp[x][y][z] = false;
                    }
                    else if(y - x == 1)
                    {
                        if(s1[y] == s2[z] && s1[x] == s2[z+1]) dp[x][y][z] = true;
                        else if(s1[y] == s2[z+1] && s1[x] == s2[z]) dp[x][y][z] = true;
                        else dp[x][y][z] = false;
                    }
                    else
                    {
                        dp[x][y][z] = false;
                        for(int i = 0; i <= y-x-1; i++)
                        {
                            bool tmp1 = (dp[x][x+i][z] && dp[x+i+1][y][z+i+1]);
                            bool tmp2 = (dp[x][x+i][z+y-x-i] && dp[x+i+1][y][z]);
                            bool tmp = tmp1 || tmp2;
                            dp[x][y][z] = dp[x][y][z] || tmp;
                        }
                    }
                }
            }
        }
    }
    
    
    bool result = dp[0][s1_len-1][0];
    
    for(int i = 0; i < s1_len; i++)
    {
        dp[i] = new bool*[s1_len];
        for(int j = 0; j < s1_len; j++)
        {
            delete [] dp[i][j];
        }
        delete [] dp[i];
    }
    delete [] dp;
    return result;
}

//总结：这个做法就特别low了
//开始没考虑一个问题：动归的顺序？
//既然由小到大
//你为啥循环位置下标？
//序列从短到长，先循环长度

int main(int argc, const char * argv[]) {
    string s1 = "great";
    string s2 = "rgtae";
    cout<<isScramble(s1, s2)<<endl;
    return 0;
}
