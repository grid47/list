
+++
authors = ["grid47"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3: Longest Substring Without Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.jpeg" 
    alt="A flowing ribbon with distinct, colorful segments, twisting and avoiding repetition."
    caption="Solution to LeetCode 3: Longest Substring Without Repeating Characters Problem"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #4: Median of Two Sorted Arrays](https://grid47.xyz/posts/leetcode-4-median-of-two-sorted-arrays-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}