
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 522: Longest Uncommon Subsequence II"
date = "2023-05-26"
description = "Solution to Leetcode 522"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-uncommon-subsequence-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        if(strs.empty()) return -1;
        int rst = -1;
        for(auto i = 0; i < strs.size(); i++) {
            int j = 0;
            for(; j < strs.size(); j++) {
                if( i == j ) continue;
                if(LCS(strs[i], strs[j])) break;
            }
            if (j == strs.size())
            rst = max(rst, static_cast<int>(strs[i].size()));
        }
        return rst;
    }
    
    bool LCS(const string& a, const string& b) {
        if(b.size() < a.size()) return false;

        int i = 0;
        for(auto ch : b)
        if (i < a.size() && a[i] == ch) i++;

        return i == a.size();
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

