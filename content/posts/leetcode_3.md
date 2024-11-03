
+++
authors = ["Crafted by Me"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3: Longest Substring Without Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prv = -1, len = 0;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i]))
                prv = max(prv, mp[s[i]]);
            mp[s[i]] = i;
            len = max(len, i - prv);
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3.md" >}}
---
{{< youtube wiGpQwVHdE0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #4: Median of Two Sorted Arrays](https://grid47.xyz/posts/leetcode_4) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

