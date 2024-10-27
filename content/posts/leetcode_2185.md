
+++
authors = ["Yasir"]
title = "Leetcode 2185: Counting Words With a Given Prefix"
date = "2018-11-04"
description = "Solution to Leetcode 2185"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/counting-words-with-a-given-prefix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int prefixCount(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() < s.size()) continue;
            bool flag = true;
            for(int i = 0; i < s.size(); i++) {
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

