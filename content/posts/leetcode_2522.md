
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2522: Partition String Into Substrings With Values at Most K"
date = "2017-12-05"
description = "Solution to Leetcode 2522"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string str;
    vector<map<int, int>> mem;
    
    int dp(int idx, int k, int num) {
        
        if(idx == str.size()) return 1;
        
        if(mem[idx].count(num)) return mem[idx][num];

        int ans = 1 + dp(idx + 1, k, str[idx] - '0');

        long long net = (long long)num * 10 + (str[idx] - '0');
        if(net <= k) {
            ans = min(ans, dp(idx + 1, k, net));
        }

        return mem[idx][num] = ans;
    }
    
    int minimumPartition(string s, int k) {
        str = s;
        for(char x: s)
            if(x - '0' > k) return -1;
        mem.resize(s.size());
        int ans = dp(0, k, 0);
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

