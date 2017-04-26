//
//  main.cpp
//  ZigZag Conversion
//
//  Created by zzqmyos on 17/4/26.
//  Copyright © 2017年 zzqmyos. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string convert(string s, int numRows) {
    int s_len = int(s.length());
    if(s_len == 0) return "";
    if(numRows == 1) return s;
    int tmp_len = s_len;
    string tmp_s = s;
    string set_s = "";
    vector<string>result;
    string resStr;
    int setLen = numRows*2-2;
    int i = 1;
    while(1)
    {
        if(tmp_len >= setLen)
        {
            set_s = tmp_s.substr(0,setLen);
            tmp_s = tmp_s.substr(setLen,tmp_len-setLen);
            tmp_len = tmp_len-setLen;
            string row_s = set_s.substr(0,numRows);
            result.push_back(row_s);
            for(int i = 1; i <= numRows-2; i++)
            {
                string remain_s(numRows, ' ');
                remain_s[numRows-i-1] = set_s[numRows+i-1];
                result.push_back(remain_s);
            }
        }
        else
        {
            set_s = tmp_s;
            if(tmp_len >= numRows)
            {
                string row_s = tmp_s.substr(0,numRows);
                tmp_s = tmp_s.substr(numRows,tmp_len-numRows);
                tmp_len = tmp_len-numRows;
                result.push_back(row_s);
                if(tmp_len > 0)
                {
                    for(int i = 1; i <= tmp_len; i++)
                    {
                        string remain_s(numRows, ' ');
                        remain_s[numRows-i-1] = tmp_s[i-1];
                        result.push_back(remain_s);
                    }
                }
            }
            else
            {
                string remain1_s = tmp_s;
                for(int i = 1; i <= numRows-tmp_len;i++)
                {
                    remain1_s.push_back(' ');
                }
                result.push_back(remain1_s);
            }
            break;
        }
    }
    int res_size = int(result.size());
    for(int i = 0; i < numRows; i++)
    {
        for(int j = 0; j < res_size; j++)
        {
            if(result[j][i] != ' ')resStr.push_back(result[j][i]);
        }
    }
    return resStr;
}

int main(int argc, const char * argv[]) {
    cout<<convert("ABCDE", 4)<<endl;
    return 0;
}
