
+++
authors = ["Crafted by Me"]
title = "Leetcode 468: Validate IP Address"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 468: Validate IP Address in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/468.md" >}}
---
{{< youtube Vdz6JaEtE3g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #469: Convex Polygon](https://grid47.xyz/posts/leetcode_469) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

