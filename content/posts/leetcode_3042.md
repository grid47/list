
+++
authors = ["Crafted by Me"]
title = "Leetcode 3042: Count Prefix and Suffix Pairs I"
date = "2016-07-04"
description = "Solution to Leetcode 3042"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wds;
    
    bool pre(int i, int j) {
        int p = 0, q = 0;
        if(wds[j].size() < wds[i].size()) return false;
        while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
            p++; q++;
        }
        return p == wds[i].size();
    }
    
    bool post(int i, int j) {
        int p = wds[i].size() - 1, q = wds[j].size() - 1;
        if(p > q) return false;
        while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
            p--; q--;
        }
        return p == -1;
    }    
    
    int countPrefixSuffixPairs(vector<string>& w) {
        wds = w;
        int n = w.size(), cnt = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
        
        return cnt;
        
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

