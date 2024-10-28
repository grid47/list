
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 468: Validate IP Address"
date = "2023-07-19"
description = "Solution to Leetcode 468"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/validate-ip-address/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string validIPAddress(string queryIP) {
        for(char ch: queryIP) {
            if (ch == '.') {
                if(checkIPv4(queryIP))
                    return "IPv4";
                return "Neither";
            } else if (ch == ':') {
                if(checkIPv6(queryIP))                
                    return "IPv6";
                return "Neither";
            }
        }
        return "Neither";
    }

    bool checkIPv4(string s) {
        s += '.';
        stringstream ss(s);
        string str;
        int n_mark = 0;
        while(getline(ss, str, '.')) {
            if(str.size() < 1 || str.size() > 3) return false;
            for(char ip: str) {
                if(ip<='9' && ip >= '0') continue;
                else return false;
            }
            if((str[0] == '0' && str[1] == '0') || (str[0] == '0' && str[1] >= '0' && str[1] <= '9'))
            return false;
            if(stoi(str) > 255) return false;
            n_mark++;
        }
        if(n_mark != 4) return false;
        return true;
    }

    bool checkIPv6(string s) {
        s += ':';
        stringstream ss(s);
        string str;
        int n_mark = 0;
        while(getline(ss, str, ':')) {
            if(str.size() < 1 || str.size() > 4)
            return false;

            for(char ip: str) {
                if((ip >= '0' && ip <= '9') || (ip >= 'a' && ip <= 'f') || (ip>= 'A' && ip<='F'))
                continue;
                else return false;
            }
            n_mark++;
        }
        if(n_mark != 8) return false;
        return true;
    }

};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

