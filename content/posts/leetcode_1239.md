
+++
authors = ["Crafted by Me"]
title = "Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters"
date = "2021-06-12"
description = "In-depth solution and explanation for Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

