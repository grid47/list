
+++
authors = ["Yasir"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2018-08-26"
description = "Solution to Leetcode 2255"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() > s.size()) continue;
            bool flag = true;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

