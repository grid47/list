
+++
authors = ["grid47"]
title = "Leetcode 468: Validate IP Address"
date = "2024-09-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 468: Validate IP Address in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/468.webp"
youtube = "Vdz6JaEtE3g"
youtube_upload_date="2020-06-16"
youtube_thumbnail="https://i.ytimg.com/vi/Vdz6JaEtE3g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/validate-ip-address/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/468.webp" 
    alt="A glowing sequence where a valid IP address is formed, each octet softly illuminated as it passes validation."
    caption="Solution to LeetCode 468: Validate IP Address Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #469: Convex Polygon](https://grid47.xyz/leetcode/solution-469-convex-polygon/) |
| --- |