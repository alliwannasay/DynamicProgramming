//
//  main.cpp
//  Word Break2
//
//  Created by zzqmyos on 17/3/26.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> searchResult_1(vector<vector<int>>& dp,string s,int start)//从左到右，遍历字符串再深搜
{
    int s_len = int(s.length());
    vector<string>result;
    bool restart = 0;
    if(start == s_len)
    {
        result.push_back("");
        return result;
    }
    for(int i = start;i < s_len;i++)
    {
        if(dp[i].size() != 0)
        {
            for(int j = int(dp[i].size() - 1) ; j >= 0;j--)
            {
                int thisSit = dp[i][j];
                if(thisSit != start - 1)
                {
                    continue;
                }
                if(dp[i][j] < start-1)
                {
                    continue;
                }
                string thisWord = s.substr(thisSit+1,i-thisSit);
                vector<string>subvec = searchResult_1(dp,s,i+1);
                for(int k = 0;k < subvec.size();k++)
                {
                    string thisCombine = thisWord + " " + subvec[k];
                    result.push_back(thisCombine);
                    restart = 1;
                }
                
            }
        }
    }
    return result;
}

vector<string> searchResult_2(vector<vector<int>>& dp,string s,int end)//从右到左深搜
{
    vector<string>result;
    if(end == -1)
    {
        result.push_back("");
        return result;
    }
    if(dp[end].size()==0)
    {
        return result;
    }
    int thisdpsize = int(dp[end].size());
    for(int i= 0; i < thisdpsize;i++)
    {
        int next = dp[end][i];
        string thisWord = s.substr(next+1,end-next);
        vector<string>subvec = searchResult_2(dp,s,next);
        for(int k = 0;k < subvec.size();k++)
        {
            string thisCombine;
            if(subvec[k]=="")
            {
                thisCombine = thisWord;
            }
            else thisCombine = subvec[k] + " " + thisWord;
            result.push_back(thisCombine);
        }
    }
    return result;
}

vector<string> searchResult_3(vector<vector<int>>& dp,string s)
{
    vector<string>result;
    int s_len = int(s.length());
    if(dp[s_len-1].size() == 0) return result;
    vector<vector<string>>sdp;
    sdp.resize(s_len);
    for(int i = 0;i < s_len;i++)
    {
        if(dp[i].size()==0) continue;
        int dpisize = int(dp[i].size());
        for(int k = 0;k < dpisize;k++)
        {
            int pre = dp[i][k];
            string thisWord = s.substr(pre+1,i-pre);
            if(pre == -1)
            {
                sdp[i].push_back(thisWord);
                continue;
            }
            int presize = int(sdp[pre].size());
            for(int j = 0; j < presize;j++)
            {
                string lastCombine = sdp[pre][j];
                string thisCombine;
                if(lastCombine == "") thisCombine = thisWord;
                else thisCombine = sdp[pre][j] + " " + thisWord;
                sdp[i].push_back(thisCombine);
            }
        }
        
    }
    return sdp[s_len-1];
}



vector<string> wordBreak_1(string s, vector<string>& wordDict) {
    int s_len = int(s.length());
    vector<vector<int>> dp;
    dp.resize(s_len);
    
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = -1; j <= i - 1; j++)
        {
            if(dp[j].size() != 0 || j == -1)
            {
                string remain = s.substr(j+1,i-j);
                
                if(find(wordDict.begin(),wordDict.end(),remain)!= wordDict.end())
                {
                    dp[i].push_back(j);
                }
            }
        }
    }
//    vector<string>result = searchResult_1(dp,s,0);
//    vector<string>result = searchResult_2(dp,s,s_len-1);
    vector<string>result = searchResult_3(dp,s);
    return result;
}

bool wordBreak_bool(string s, vector<string>& wordDict) {
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


vector<string> wordBreak(string s, vector<string>& wordDict){
    int s_len = int(s.length());
    vector<vector<string>>sdp;
    sdp.resize(s_len);
    bool isbreak = wordBreak_bool(s,wordDict);
    if(!isbreak)
    {
        vector<string> result;
        return result;
    }
    for(int i = 0; i < s_len; i++)
    {
        for(int j = -1; j <= i - 1; j++)
        {
            if(sdp[j].size() != 0 || j == -1)
            {
                string remain = s.substr(j+1,i-j);
                if(find(wordDict.begin(),wordDict.end(),remain)!= wordDict.end())
                {
                    if(j == -1)
                    {
                        sdp[i].push_back(remain);
                        continue;
                    }
                    int sdpjsize = int(sdp[j].size());
                    for(int k = 0;k < sdpjsize;k++)
                    {
                        string lastCombine = sdp[j][k];
                        string thisCombine;
                        if(lastCombine == "") thisCombine = remain;
                        else thisCombine = lastCombine + " " + remain;
                        sdp[i].push_back(thisCombine);

                    }
                }
            }
        }
    }
    return sdp[s_len-1];
}

int main(int argc, const char * argv[]) {
    string s = "a";
    vector<string> dict;
//    dict.push_back("a");
//    
//    dict.push_back("aa");
//    
//    dict.push_back("aaa");
//    
//    dict.push_back("aaaa");
//    
//    dict.push_back("aaaaa");
//    
//    dict.push_back("aaaaaa");
//    
//    dict.push_back("aaaaaaa");
//    
//    dict.push_back("aaaaaaaa");
//    
//    dict.push_back("aaaaaaaaa");
//    
//    dict.push_back("aaaaaaaaaa");


    vector<string>result = wordBreak(s,dict);
    cout<<"Result:"<<endl;
    for(int k = 0; k < result.size();k++)
    {
        cout << result[k] << "*\n";
    }
    return 0;
}
