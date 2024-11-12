
+++
authors = ["grid47"]
title = "Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(auto &s: arr) {
            bitset<26> a;
            for(char x: s)
                a.set(x-'a');
            int n = a.count();
            if(n < s.size()) continue;
            for(int i = dp.size() -1; i >= 0; i--) {
                bitset c = dp[i];
                if ((c&a).any()) continue;
                dp.push_back(c|a);
                res = max(res, (int) c.count()+n);
                
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1239.md" >}}
---
{{< youtube d4SPuvkaeoo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1247: Minimum Swaps to Make Strings Equal](https://grid47.xyz/posts/leetcode-1247-minimum-swaps-to-make-strings-equal-solution/) |
| --- |
